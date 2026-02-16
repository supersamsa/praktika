CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
TARGETS = task1 task2 task3 task4 task5 task6 task7 task8 task9 task10 task11 task12 task13 task14 task15 task16 task17 task18

all: $(TARGETS)

task1: task1.c
	$(CC) $(CFLAGS) -o $@ $<

task2: task2.c
	$(CC) $(CFLAGS) -o $@ $<

task3: task3.c
	$(CC) $(CFLAGS) -o $@ $<

task4: task4.c
	$(CC) $(CFLAGS) -o $@ $<

task5: task5.c
	$(CC) $(CFLAGS) -o $@ $<

task6: task6.c
	$(CC) $(CFLAGS) -o $@ $<

task7: task7.c
	$(CC) $(CFLAGS) -o $@ $<

task8: task8.c
	$(CC) $(CFLAGS) -o $@ $<

task9: task9.c
	$(CC) $(CFLAGS) -o $@ $<

task10: task10.c
	$(CC) $(CFLAGS) -o $@ $<

task11: task11.c
	$(CC) $(CFLAGS) -o $@ $<

task12: task12.c
	$(CC) $(CFLAGS) -o $@ $<

task13: task13.c
	$(CC) $(CFLAGS) -o $@ $<

task14: task14.c
	$(CC) $(CFLAGS) -o $@ $<

task15: task15.c
	$(CC) $(CFLAGS) -o $@ $<

task16: task16.c
	$(CC) $(CFLAGS) -o $@ $<

task17: task17.c
	$(CC) $(CFLAGS) -o $@ $<

task18: task18.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

rebuild: clean all

test: all
	@for task in $(TARGETS); do ./$$task < /dev/null || true; done

help:
	@echo "make all"
	@echo "make taskN"
	@echo "make clean"
	@echo "make rebuild"
	@echo "make test"
	@echo "make help"

.PHONY: all clean rebuild test help
