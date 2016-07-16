NAME := paphics

CC := gcc
CFLAGS :=
LDFLAGS := -l$(NAME) -lpthread -lsubunit -lrt -lcheck
LOCAL_LDFLAGS := -lm
TRAVIS_LDFLAGS := -lfloor

C_FILES	:= $(wildcard ./*.c)
O_FILES := $(C_FILES:./%.c=./%.o)

./%.o: ./%.c Makefile
ifeq ($(TRAVIS),)
	$(CC) -o $@ -x c $< $(CFLAGS) $(LDFLAGS) $(LOCAL_LDFLAGS)
else
	$(CC) -o $@ -x c $< $(CFLAGS) $(LDFLAGS) $(TRAVIS_LDFLAGS)
endif

all: build test mrproper

build: $(O_FILES) Makefile

test:
	$(O_FILES)

clean:

mrproper: clean
	rm -rf $(O_FILES)
