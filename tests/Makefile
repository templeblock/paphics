NAME := paphics

CC := gcc
CFLAGS :=
LDFLAGS := -L/usr/local/lib -lpaphics -lcheck -lpthread -lsubunit -lrt -lm

C_FILES	:= $(wildcard ./*.c)
O_FILES := $(C_FILES:./%.c=./%.o)

./%.o: ./%.c Makefile
	$(CC) $(CFLAGS) -x c $< $(LDFLAGS) -o $@

all: build test run mrproper

build: $(O_FILES) Makefile

test:
  LD_LIBRARY_PATH=/usr/local/lib
  export LD_LIBRARY_PATH

run:
	$(O_FILES)

clean:

mrproper: clean
	rm -rf $(O_FILES)