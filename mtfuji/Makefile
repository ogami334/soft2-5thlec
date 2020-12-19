TARGET = bin/mtfuji
OBJS = src/mtfuji.o src/sort.o src/optimize.o src/func1.o
LIB  = lib/libmtfuji.a
$(TARGET): $(OBJS) $(LIB)
	$(CC) -I./include -o $@ $(OBJS) $(LIB)
lib/libmtfuji.a: src/optimize.o src/sort.o src/func1.o
	ar rsv $(LIB) $<
src/mtfuji.o: src/mtfuji.c
	$(CC) -o src/mtfuji.o -I./include -c src/mtfuji.c
src/sort.o: src/sort.c
	$(CC) -o src/sort.o -I./include -c src/sort.c
src/optimize.o: src/optimize.c
	$(CC) -o src/optimize.o -I./include -c src/optimize.c
src/func1.o: src/func1.c
	$(CC) -o src/func1.o -I./include -c src/func1.c
.PHONY: clean
clean:
	rm -f bin/mtfuji
	rm -f src/*.o