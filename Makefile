.PHONY: default all install-all install install-dev get-dep-debian-all get-dep-debian get-dep-dev-debian build format build-doc build-doc-pdf clean mrproper libs

NAME := paphics

VERSION := 0.0.1

SRC_DIR := ./src
HEAD_DIR := ./head
export BUILD_DIR=$(PWD)/build
LOG_DIR := ./logs
DOC_DIR := ./doc

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wdouble-promotion -Wformat -Winit-self  -Wmissing-include-dirs -Wswitch-default  -Wswitch-enum -Wunused -Wunused-parameter -Wuninitialized -Wunknown-pragmas -fstrict-overflow -Wstrict-overflow=2 -Wsuggest-attribute=const -Wsuggest-attribute=pure -Wmissing-format-attribute -Wstrict-aliasing -Wtrampolines -Wfloat-equal -Wundef -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wconversion -Wjump-misses-init -Wlogical-op -Wno-aggressive-loop-optimizations -Wstrict-prototypes -Wmissing-declarations -Wredundant-decls -Wpacked -Wpadded -Wnested-externs -Winline -Wvla -Wdisabled-optimization -Wstack-protector -Wunsuffixed-float-constants -Wabi -Winvalid-pch -Wshadow -pedantic-errors --pedantic -g -Werror -O6 -pass-exit-codes -pipe -aux-info $(LOG_DIR)/aux-info.log -fsigned-char -fsigned-bitfields -fPIC
CFLAGS_LOCAL := -fdiagnostics-color=auto

FORMATTER := astyle
FORMATTERFLAGS := --style=java --indent=spaces=4 -S -N -L -w -Y -m2 -M120 -f -p -H -E -k1 -W3 -j -v -z2
FORMATTERFLAGS_LOCAL := -xn -xc -xw

INCLUDE	:= -I$(SRC_DIR) -I$(HEAD_DIR) -I/usr/include -I/usr/local/include

LDFLAGS := -L/usr/lib -L/usr/local/lib -lm -lSDL2-2.0 -lSDL2_image-2.0 -lSDL2_mixer-2.0

TARGET := lib$(NAME).so
H_FILES	:= $(wildcard $(HEAD_DIR)/*.h)
C_FILES	:= $(wildcard $(SRC_DIR)/*.c)
O_FILES := $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEP_DEBIAN := libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0
DEP_DEV_DEBIAN := build-essential astyle libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev doxygen graphviz texlive texlive-latex-extra

default: all

all: format build build-doc-pdf clean

get-dep-debian-all: get-dep-debian get-dep-dev-debian

get-dep-debian:
ifneq ($(TRAVIS),)
	apt-get -y install $(DEP_DEBIAN)
else
	apt-get install $(DEP_DEBIAN)
endif

get-dep-dev-debian:
ifneq ($(TRAVIS),)
	apt-get -y install $(DEP_DEV_DEBIAN)
else
	apt-get install $(DEP_DEV_DEBIAN)
endif

format:
ifneq ($(TRAVIS),)
	$(FORMATTER) $(FORMATTERFLAGS) $(C_FILES) $(H_FILES)
else
	$(FORMATTER) $(FORMATTERFLAGS) $(FORMATTERFLAGS_LOCAL) $(C_FILES) $(H_FILES)
endif

build: $(TARGET)

$(LOG_DIR):
	mkdir -p $(LOG_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(LOG_DIR) $(BUILD_DIR)
ifeq ($(TRAVIS),)
	$(CC) -o $@ -x c -c $< $(CFLAGS_LOCAL) $(CFLAGS) $(INCLUDE)
else
	$(CC) -o $@ -x c -c $< $(CFLAGS) $(INCLUDE)
endif

$(TARGET): $(O_FILES) Makefile libs
	$(CC) -shared -fPIC -o $@ $(O_FILES) $(LDFLAGS)

build-doc: $(LOG_DIR)
	( cat Doxyfile ; echo "PROJECT_NUMBER=$(VERSION)" ) | doxygen -

build-doc-pdf: build-doc
	cd $(DOC_DIR)/latex/ && make pdf
	mv $(DOC_DIR)/latex/refman.pdf $(DOC_DIR)/doc.pdf

install-all: install install-dev

install:
	rm -rf /usr/local/lib/$(TARGET)
	cp $(TARGET) /usr/local/lib/

install-dev:
	rm -rf /usr/local/include/$(NAME)/*
	mkdir -p /usr/local/include/$(NAME)/
	cp $(H_FILES) /usr/local/include/$(NAME)/

clean:
	rm -rf *.orig $(SRC_DIR)/*.orig $(HEAD_DIR)/*.orig
	rm -rf $(BUILD_DIR) *.tgz
	rm -rf $(LOG_DIR)
	rm -rf $(DOC_DIR)/docbook $(DOC_DIR)/latex

mrproper: clean
	rm -rf $(TARGET) $(DOC_DIR)
