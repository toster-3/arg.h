# Makefile for arg.h examples

CFLAGS = -Wall -Wno-missing-braces -pedantic
CC ?= cc

all: 01_basic_usage 02_long_options 03_miscellaneous

01_basic_usage: 01_basic_usage.c
	${CC} ${CFLAGS} -o $@ $<

02_long_options: 02_long_options.c
	${CC} ${CFLAGS} -o $@ $<

03_miscellaneous: 03_miscellaneous.c
	${CC} ${CFLAGS} -o $@ $<

clean:
	rm -f 01_basic_usage 02_long_options 03_miscellaneous

.PHONY: all clean
