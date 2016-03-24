.PHONY: default all clean mrproper tar astyle libs

SRC_DIR := ./src

CC	:= gcc
CFLAGS	:= -std=c99 -W -Wall -Wshadow --pedantic
NAME := demo

LIBS	:= -lm -lSDL2-2.0 -lSDL2_image-2.0
export BUILD_DIR=$(PWD)/build

TARGET		:= main
H_FILES	:= $(wildcard $(SRC_DIR)/*.h)
C_FILES	:= $(wildcard $(SRC_DIR)/*.c)
O_FILES		:= $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

default: all

all : astyle build run clean

build : $(TARGET)

$(TARGET): $(O_FILES) $(STATIC_LIBS) Makefile libs
	$(CC) -o $(NAME) $(O_FILES) $(STATIC_LIBS) $(LDFLAGS) $(LIBS)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(BUILD_DIR)
	$(CC) -c $< $(CFLAGS) $(INCLUDE) -o $@

clean:
	-rm -rf $(BUILD_DIR) *.orig *.tgz $(NAME) src/*.orig

mrproper: clean
	-rm -rf $(TARGET)

install :
	apt-get install astyle gcc libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev

run :
	./$(NAME)

astyle:
	astyle $(C_FILES) $(H_FILES)
