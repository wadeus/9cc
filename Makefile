CFLAGS=-std=c11 -g -fno-common
OBJS=main.o tokenize.o parse.o codegen.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

9cc: $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS)

test: 9cc
		./test.sh

clean:
		rm -f 9cc *.o *~ tmp* *.out

.PHONY: test clean
