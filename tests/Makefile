NAME := paphics

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wdouble-promotion -Wformat -Winit-self  -Wmissing-include-dirs -Wswitch-default  -Wswitch-enum -Wunused -Wunused-parameter -Wuninitialized -Wunknown-pragmas -fstrict-overflow -Wstrict-overflow=2 -Wmissing-format-attribute -Wstrict-aliasing -Wtrampolines -Wundef -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wconversion -Wjump-misses-init -Wlogical-op -Wno-aggressive-loop-optimizations -Wstrict-prototypes -Wredundant-decls -Wpacked -Wpadded -Wnested-externs -Winline -Wvla -Wdisabled-optimization -Wstack-protector -Wunsuffixed-float-constants -Wabi -Winvalid-pch -Wshadow -pedantic-errors --pedantic -g -Werror -O6 -pass-exit-codes -pipe -fsigned-char -fsigned-bitfields
LDFLAGS := -l$(NAME) -lcheck -lpthread -lsubunit -lrt -lm

C_FILES	:= $(wildcard ./*.c)
O_FILES := $(C_FILES:./%.c=./%.o)
GCOV_FILES := $(C_FILES:./%_test.c=./%.c.gcov)

LIB_DIR := ./lib

./%.o: ./%.c Makefile
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

all: build-lib build export run

$(LIB_DIR):
	rm -rf $(LIB_DIR)
	mkdir -p $(LIB_DIR)

build-lib: $(LIB_DIR)
	cd ../ && make build CFLAGS="-O0 --coverage -fPIC -g" LDFLAGS+="-lgcov"
	cp ../lib$(NAME).so $(LIB_DIR)/

build: $(O_FILES) Makefile

export:
  LD_LIBRARY_PATH=$(LIB_DIR)
  export LD_LIBRARY_PATH

run:
	for f in $(O_FILES); do \
	    $$f ; \
	done

./%.c.gcov: ./%_test.gcno
	gcov -o $(subst .c.gcov,.gcno,$@) ../src/$(subst _test.c.gcov,.c,$@)

coverage-tmp: $(GCOV_FILES)

coverage:

clean:
	rm -rf *.gcda *.gcno *.gcov *.orig

mrproper: clean
	rm -rf $(O_FILES)
	rm -rf $(LIB_DIR)
