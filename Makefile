.PHONY: default all install-dep-dev-debian format run clean mrproper libs

NAME := graphics

VERSION := 0.0.0

SRC_DIR := ./src
HEAD_DIR := ./head
export BUILD_DIR=$(PWD)/build
LIB_DIR := ./libs
LOG_DIR := ./logs
ifneq ($(TRAVIS),)
export LD_RUN_PATH=/usr/local/lib:$LD_RUN_PATH
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
endif

CC := gcc
CFLAGS_BASE := -Wall -Wextra -Wdouble-promotion -Wformat -Winit-self  -Wmissing-include-dirs -Wswitch-default  -Wswitch-enum -Wunused -Wunused-parameter -Wuninitialized -Wunknown-pragmas -fstrict-overflow -Wstrict-overflow=2 -Wsuggest-attribute=const -Wmissing-format-attribute -Wstrict-aliasing -Wtrampolines -Wfloat-equal -Wundef -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wconversion -Wjump-misses-init -Wlogical-op -Wstrict-prototypes -Wmissing-declarations -Wredundant-decls -Wpacked -Wpadded -Wnested-externs -Winline -Wvla -Wdisabled-optimization -Wstack-protector -Wunsuffixed-float-constants -Wabi -Winvalid-pch -Wshadow -pedantic-errors --pedantic -g -Werror -O6 -pass-exit-codes -pipe -aux-info $(LOG_DIR)/aux-info.log -fsigned-char -fsigned-bitfields -fPIC
CFLAGS_LOCAL := -std=c11 -Wno-aggressive-loop-optimizations -fdiagnostics-color=auto
CFLAGS_TRAVIS := -std=c99

FORMATTER := astyle
FORMATTERFLAGS := --style=java --indent=spaces=4 -xn -xc -S -N -L -w -xw -Y -m2 -M120 -f -p -H -E -k1 -W3 -j -v -z2

INCLUDE	:= -I$(SRC_DIR) -I$(HEAD_DIR) -I/usr/include -I/usr/local/include

LIBS_BASE := -L/usr/lib -L/usr/local/lib -lm
LIBS_LOCAL := -lSDL2-2.0 -lSDL2_image-2.0 -lSDL2_mixer-2.0

TARGET := $(NAME).out
TARGET_STATIC := lib$(NAME).a
TARGET_DYNAMIC := lib$(NAME).so
H_FILES	:= $(wildcard $(HEAD_DIR)/*.h)
C_FILES	:= $(wildcard $(SRC_DIR)/*.c)
O_FILES := $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
STATIC_LIBS := $(wildcard $(LIB_DIR)/*.a)

DEP_DEBIAN := libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0
DEP_DEV_DEBIAN := build-essential astyle libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev

default: all

all: format build-dynamic-lib clean

install-all: install install-dev

install: copy-dynamic-lib

install-dev: copy-headers

get-dep-debian-all: get-dep-debian get-dep-dev-debian

get-dep-debian:
ifneq ($(TRAVIS),)
	sudo apt-get -y install $(DEP_DEBIAN)
else
	sudo apt-get install $(DEP_DEBIAN)
endif

get-dep-dev-debian:
ifneq ($(TRAVIS),)
	sudo apt-get -y install $(DEP_DEV_DEBIAN)
else
	sudo apt-get install $(DEP_DEV_DEBIAN)
endif

format:
	$(FORMATTER) $(FORMATTERFLAGS) $(C_FILES) $(H_FILES)

build: $(LOG_DIR) $(TARGET)

$(LOG_DIR):
	mkdir -p $(LOG_DIR)

$(BUILD_DIR)/%.a:
	cd $(SRC_DIR)/$* && $(MAKE) all

$(TARGET): $(O_FILES) $(STATIC_LIBS) Makefile libs
	$(CC) -o $@ $(O_FILES) $(STATIC_LIBS) $(LIBS) $(LDFLAGS)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(BUILD_DIR)
ifeq ($(TRAVIS),)
	$(CC) -o $@ -x c -c $< $(CFLAGS_LOCAL) $(CFLAGS_BASE) $(INCLUDE)
else
	$(CC) -o $@ -x c -c $< $(CFLAGS_LOCAL) $(CFLAGS_BASE) $(INCLUDE)
endif

build-static-lib: $(LOG_DIR) $(TARGET_STATIC)

$(TARGET_STATIC): build
	ar -q lib$(NAME).a $(TARGET)

build-dynamic-lib: $(LOG_DIR) $(TARGET_DYNAMIC)

$(TARGET_DYNAMIC): $(O_FILES) $(STATIC_LIBS) Makefile libs
ifeq ($(TRAVIS),)
	$(CC) -shared -fPIC -o $@ $(O_FILES) $(STATIC_LIBS) $(LIBS_BASE) $(LIBS_LOCAL)
else
	$(CC) -shared -fPIC -o $@ $(O_FILES) $(STATIC_LIBS) $(LIBS_BASE) $(LIBS_TRAVIS)
endif

copy-dynamic-lib:
	sudo rm -rf /usr/local/lib/$(TARGET_DYNAMIC)
	sudo cp $(TARGET_DYNAMIC) /usr/local/lib/

copy-headers:
	sudo rm -rf /usr/local/include/$(NAME)/*
	sudo mkdir -p /usr/local/include/$(NAME)/
	sudo cp $(H_FILES) /usr/local/include/$(NAME)/

run:
	./$(TARGET)

clean:
	-rm -rf *.orig $(SRC_DIR)/*.orig $(HEAD_DIR)/*.orig
	-rm -rf $(BUILD_DIR) *.tgz
	-rm -rf $(LOG_DIR)

mrproper: clean
	-rm -rf $(TARGET) $(TARGET_STATIC) $(TARGET_DYNAMIC)
