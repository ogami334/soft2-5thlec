TARGET = bin/qsort
OBJS = src/main.o src/qsort_lib.o
LIB  = lib/libqsort.a
$(TARGET): $(OBJS) $(LIB)
	$(CC) -I./include -o $@ $(OBJS) -L./lib -lqsort

src/main.o: src/main.c
	$(CC) -o src/main.o -I./include -c src/main.c
.PHONY: clean
clean:
	rm -f bin/qsort
	rm -f src/*.o