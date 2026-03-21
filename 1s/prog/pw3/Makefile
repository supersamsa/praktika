CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2

TARGETS = task1 task2 task3 task4 task5 task6 task7 task8
SOURCES = task1.c task2.c task3.c task4.c task5.c task6.c task7.c task8.c

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

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGETS)

release: CFLAGS += $(RELEASE_FLAGS)
release: $(TARGETS)

clean:
	rm -f $(TARGETS) *.o

rebuild: clean all

run: $(TARGETS)
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

help:
	@echo "Доступные команды:"
	@echo "  make all      - компиляция всех программ"
	@echo "  make debug    - компиляция с отладочной информацией"
	@echo "  make release  - компиляция с оптимизацией"
	@echo "  make clean    - удаление скомпилированных файлов"
	@echo "  make rebuild  - пересборка всех программ"
	@echo "  make run      - запуск всех программ"
	@echo "  make help     - показать эту справку"
	@echo ""
	@echo "Отдельные программы:"
	@echo "  make task1 - скомпилировать только task1"
	@echo "  make task2 - скомпилировать только task2"
	@echo "  ... и т.д. для task3-task8"

.PHONY: all debug release clean rebuild run help

info:
	@echo "Программы:"
	@echo "  task1 - Форматирование имени и фамилии"
	@echo "  task2 - Работа с именем"
	@echo "  task3 - Форматы вывода чисел"
	@echo "  task4 - Рост и имя"
	@echo "  task5 - Время загрузки файла"
	@echo "  task6 - Имя и количество символов"
	@echo "  task7 - Сравнение точности float и double"
	@echo "  task8 - Расход топлива"
