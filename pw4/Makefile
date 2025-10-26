# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGETS = task1 task2 task3 task4 task5 task6 task7 task8 task9

# Правило по умолчанию - собирает все цели
all: $(TARGETS)

# Правила для каждой программы
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

task9: task9.c
	$(CC) $(CFLAGS) -o task9 task9.c

# Правило для очистки собранных файлов
clean:
	rm -f $(TARGETS)

# Правило для пересборки
rebuild: clean all

# Правило для запуска всех программ (последовательно)
run: all
	@echo "=== Запуск task1 ==="
	@./task1 || true
	@echo ""
	@echo "=== Запуск task2 ==="
	@./task2 || true
	@echo ""
	@echo "=== Запуск task3 ==="
	@./task3 || true
	@echo ""
	@echo "=== Запуск task4 ==="
	@./task4 || true
	@echo ""
	@echo "=== Запуск task5 ==="
	@./task5 || true
	@echo ""
	@echo "=== Запуск task6 ==="
	@./task6 || true
	@echo ""
	@echo "=== Запуск task7 ==="
	@./task7 || true
	@echo ""
	@echo "=== Запуск task8 ==="
	@./task8 || true
	@echo ""
	@echo "=== Запуск task9 ==="
	@./task9 || true

# Помощь
help:
	@echo "Доступные команды:"
	@echo "  make all     - собрать все программы"
	@echo "  make taskN   - собрать конкретную программу (замените N на номер)"
	@echo "  make clean   - удалить все собранные программы"
	@echo "  make rebuild - пересобрать все программы"
	@echo "  make run     - собрать и запустить все программы"
	@echo "  make help    - показать эту справку"

# Объявляем фиктивные цели
.PHONY: all clean rebuild run help
