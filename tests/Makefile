NAME := paphics

CC := gcc
CFLAGS :=
LDFLAGS := -lpaphics -L/usr/local/lib -lcheck -lpthread -lsubunit -lrt -lm

INCLUDE := -I/usr/local/include

C_FILES	:= $(wildcard ./*.c)
O_FILES := $(C_FILES:./%.c=./%.o)

./%.o: ./%.c Makefile
	$(CC) $(CFLAGS) -x c $< $(LDFLAGS) $(INCLUDE) -o $@

all: build test mrproper

build: $(O_FILES) Makefile

test:
	$(O_FILES) $(LDFLAGS)

clean:

mrproper: clean
	rm -rf $(O_FILES)
