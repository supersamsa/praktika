# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGETS = task1 task2 task3 task4 task5 task6 task7 task8

# Правило по умолчанию - компилирует все задачи
all: $(TARGETS)

# Правила для каждой задачи
task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

task2: task2.c
	$(CC) $(CFLAGS) -o task2 task2.c

task3: task3.c
	$(CC) $(CFLAGS) -o task3 task3.c

task4: task4.c
	$(CC) $(CFLAGS) -o task4 task4.c

task5: task5.c
	$(CC) $(CFLAGS) -o task5 task5.c

task6: task6.c
	$(CC) $(CFLAGS) -o task6 task6.c

task7: task7.c
	$(CC) $(CFLAGS) -o task7 task7.c

task8: task8.c
	$(CC) $(CFLAGS) -o task8 task8.c

# Правило для запуска всех программ
run: all
	@echo "=== Задача 1 ==="
	./task1
	@echo ""
	@echo "=== Задача 2 ==="
	@echo "Введите 66 для теста:"
	@echo "66" | ./task2
	@echo ""
	@echo "=== Задача 3 ==="
	./task3
	@echo ""
	@echo "=== Задача 4 ==="
	@echo "Введите 64.25 для теста:"
	@echo "64.25" | ./task4
	@echo ""
	@echo "=== Задача 5 ==="
	@echo "Введите 25 для теста:"
	@echo "25" | ./task5
	@echo ""
	@echo "=== Задача 6 ==="
	@echo "Введите 2 для теста:"
	@echo "2" | ./task6
	@echo ""
	@echo "=== Задача 7 ==="
	@echo "Выберите 1 и введите 70 для теста:"
	@echo -e "1\n70" | ./task7
	@echo ""
	@echo "=== Задача 8 ==="
	@echo "Введите 3 для теста:"
	@echo "3" | ./task8

# Очистка скомпилированных файлов
clean:
	rm -f $(TARGETS)

# Справка
help:
	@echo "Доступные команды:"
	@echo "  make all    - скомпилировать все задачи"
	@echo "  make taskN  - скомпилировать конкретную задачу (1-8)"
	@echo "  make run    - скомпилировать и запустить все задачи с тестовыми данными"
	@echo "  make clean  - удалить скомпилированные программы"
	@echo "  make help   - показать эту справку"

.PHONY: all run clean help
