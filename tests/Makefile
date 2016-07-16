NAME := paphics

CC := gcc
CFLAGS :=
LDFLAGS := -L/usr/lib -L/usr/local/lib -lpaphics -lcheck -lpthread -lsubunit -lrt -lm
INCLUDE := -I/usr/include -I/usr/local/include

C_FILES	:= $(wildcard ./*.c)
O_FILES := $(C_FILES:./%.c=./%.o)

./%.o: ./%.c Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -x c $< $(LDFLAGS)

all: build test mrproper

build: $(O_FILES) Makefile

test:
	$(O_FILES)

clean:

mrproper: clean
	rm -rf $(O_FILES)
