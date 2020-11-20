.PHONY: all clean
all: quicksort

CFLAGS = -DCOMPUTE_MD5_PROBLEM -g -Wall -Wshadow -Wcast-align \
	-Waggregate-return -Wmissing-prototypes -Wmissing-declarations \
	-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
	-Wmissing-noreturn  \
	-Wpointer-arith -Wwrite-strings -finline-functions -O3 \
	-lrt -std=c99

LIBS= -lm -lcrypto -lssl

quicksort: quicksort.o
	$(CC) $(INCLUDES) $(DEFS) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f quicksort *.o *~
