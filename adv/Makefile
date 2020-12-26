TARGET = bin/adv_regression
OBJS = src/adv_regression.o src/optimize.o src/func.o
LIB  = lib/libadv.a
$(TARGET): $(OBJS) $(LIB)
	$(CC) -I./include -o $@ $(OBJS) $(LIB)
lib/libadv.a: src/optimize.o src/func.o
	ar rsv $(LIB) $<
src/adv_regression.o: src/adv_regression.c
	$(CC) -o src/adv_regression.o -I./include -c src/adv_regression.c
src/optimize.o: src/optimize.c
	$(CC) -o src/optimize.o -I./include -c src/optimize.c
src/func.o: src/func.c
	$(CC) -o src/func.o -I./include -c src/func.c
.PHONY: clean
clean:
	rm -f bin/adv_regression
	rm -f src/*.o