NAME := paphics

CC := gcc
CFLAGS :=
LDFLAGS := -lm -l$(NAME) -lpthread -lsubunit -lrt -lcheck

C_FILES	:= $(wildcard ./*.c)
O_FILES := $(C_FILES:./%.c=./%.o)

./%.o: ./%.c Makefile
	$(CC) -o $@ -x c $< $(CFLAGS) $(LDFLAGS)

all: build test mrproper

build: $(O_FILES) Makefile

test:
	$(O_FILES)

clean:

mrproper: clean
	rm -rf $(O_FILES)
