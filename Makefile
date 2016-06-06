.PHONY: default all install-dep-dev-debian format run clean mrproper libs

NAME := graphics

VERSION := 0.0.0

SRC_DIR := ./src
HEAD_DIR := ./head
export BUILD_DIR=$(PWD)/build
LIB_DIR := ./libs
LOG_DIR := ./logs

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wdouble-promotion -Wformat -Winit-self  -Wmissing-include-dirs -Wswitch-default  -Wswitch-enum -Wunused -Wunused-parameter -Wuninitialized -Wunknown-pragmas -fstrict-overflow -Wstrict-overflow=2 -Wsuggest-attribute=const -Wmissing-format-attribute -Wstrict-aliasing -Wtrampolines -Wfloat-equal -Wundef -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wconversion -Wjump-misses-init -Wlogical-op -Wno-aggressive-loop-optimizations -Wstrict-prototypes -Wmissing-declarations -Wredundant-decls -Wpacked -Wpadded -Wnested-externs -Winline -Wvla -Wdisabled-optimization -Wstack-protector -Wunsuffixed-float-constants -Wabi -Winvalid-pch -Wshadow -pedantic-errors --pedantic -g -Werror -O6 -pass-exit-codes -pipe -aux-info $(LOG_DIR)/aux-info.log -fsigned-char -fsigned-bitfields -fdiagnostics-color=auto -fPIC

FORMATTER := astyle
FORMATTERFLAGS := --style=java --indent=spaces=4 -xn -xc -S -N -L -w -xw -Y -m2 -M120 -f -p -H -E -k1 -W3 -j -v -z2

INCLUDE	:= -I$(SRC_DIR) -I$(HEAD_DIR) -I/usr/include

LIBS := -L/usr/lib -L/usr/local/lib -lm -lSDL2-2.0 -lSDL2_image-2.0 -lSDL2_mixer-2.0

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

install: copy-dynamic-lib mrproper

install-dep-debian:
	apt-get install $(DEP_DEBIAN)

install-dep-dev-debian:
	apt-get install $(DEP_DEV_DEBIAN)

format:
	$(FORMATTER) $(FORMATTERFLAGS) $(C_FILES) $(H_FILES)

build: $(TARGET)

$(BUILD_DIR)/%.a:
	cd $(SRC_DIR)/$* && $(MAKE) all

$(TARGET): $(O_FILES) $(STATIC_LIBS) Makefile libs
	$(CC) -o $@ $(O_FILES) $(STATIC_LIBS) $(LIBS) $(LDFLAGS)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(BUILD_DIR)
	$(CC) -o $@ -x c -c $< $(CFLAGS) $(INCLUDE)

build-static-lib: $(TARGET_STATIC)

$(TARGET_STATIC): build
	ar -q lib$(NAME).a $(TARGET)

build-dynamic-lib: $(TARGET_DYNAMIC)

$(TARGET_DYNAMIC): $(O_FILES) $(STATIC_LIBS) Makefile libs
	$(CC) -o $@ $(O_FILES) $(STATIC_LIBS) $(LIBS) -shared -fPIC

copy-dynamic-lib:
	cp $(TARGET_DYNAMIC) /usr/local/lib/

run:
	./$(TARGET)

clean:
	-rm -rf *.orig $(SRC_DIR)/*.orig $(HEAD_DIR)/*.orig
	-rm -rf $(BUILD_DIR) *.tgz
	-rm -rf $(LOG_DIR)/*

mrproper: clean
	-rm -rf $(TARGET) $(TARGET_STATIC) $(TARGET_DYNAMIC)
