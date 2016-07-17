NAME := paphics

CC := gcc
CFLAGS :=
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
