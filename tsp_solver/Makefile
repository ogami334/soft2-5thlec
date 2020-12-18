CC = gcc
TARGET = solver
OBJS = main.o solve.o plot.o city.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm *.o *~ a.out solver