CC = gcc
CFLAGS = -Wall -Wextra -O2 -g
LDFLAGS = -lm

# Исходные файлы
SRCS = main.c linear_search.c binary_search.c exponential_search.c merge_sort.c utils.c
OBJS = $(SRCS:.c=.o)
TARGET = lab1

# Правила сборки
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c search.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean run valgrind