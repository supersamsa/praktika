CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = datetime_demo
OBJS = main.o datatime.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c datatime.h
	$(CC) $(CFLAGS) -c main.c

datatime.o: datatime.c datatime.h
	$(CC) $(CFLAGS) -c datatime.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run