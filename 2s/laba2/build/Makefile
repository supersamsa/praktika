# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = lab2_program

# Пути к исходным файлам (теперь в текущей директории)
SOURCES = main.c devicestruct.c packeddevice.c
OBJECTS = main.o devicestruct.o packeddevice.o
HEADERS = devicestruct.h packeddevice.h

# Цели по умолчанию
.PHONY: all clean run docker-build docker-run docker-dev docker-clean help

all: $(TARGET)

# Линковка объектных файлов в исполняемый файл
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "✅ Сборка завершена. Исполняемый файл: $(TARGET)"
	@echo "📏 Размер структуры BitDevice:"
	@./$(TARGET) 2>/dev/null | grep "Размер" || echo "   Запустите 'make run' для просмотра"

# Компиляция .c файлов в .o
main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c -o main.o
	@echo "   Компилирован: main.c"

devicestruct.o: devicestruct.c $(HEADERS)
	$(CC) $(CFLAGS) -c devicestruct.c -o devicestruct.o
	@echo "   Компилирован: devicestruct.c"

packeddevice.o: packeddevice.c $(HEADERS)
	$(CC) $(CFLAGS) -c packeddevice.c -o packeddevice.o
	@echo "   Компилирован: packeddevice.c"

# Очистка временных файлов
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "🧹 Очистка завершена"

# Запуск программы
run: $(TARGET)
	@echo "🚀 Запуск программы:"
	@./$(TARGET)

# Docker цели
docker-build:
	@echo "🐳 Сборка Docker образа..."
	cd .. && docker build -f build/Dockerfile -t lab2-image .
	@echo "✅ Docker образ создан: lab2-image"

docker-run: docker-build
	@echo "🐳 Запуск в Docker контейнере:"
	docker run --rm lab2-image

docker-dev:
	@echo "🐳 Запуск интерактивной оболочки в Docker контейнере..."
	cd .. && docker run -it --rm -v $$(pwd):/app lab2-image /bin/bash

docker-clean:
	@echo "🐳 Удаление Docker образа..."
	docker rmi lab2-image 2>/dev/null || true
	@echo "✅ Docker образ удален"

# Многоступенчатая сборка (экономия места)
docker-build-small:
	@echo "🐳 Сборка оптимизированного Docker образа..."
	cd .. && docker build -f build/Dockerfile.multistage -t lab2-small .
	@echo "✅ Оптимизированный Docker образ создан: lab2-small"

docker-run-small: docker-build-small
	@echo "🐳 Запуск оптимизированного контейнера:"
	docker run --rm lab2-small

# Информация о размерах
docker-size:
	@echo "📊 Размеры Docker образов:"
	@docker images lab2* --format "table {{.Repository}}\t{{.Tag}}\t{{.Size}}"

# Помощь
help:
	@echo "📋 Доступные команды Make:"
	@echo "  make all              - Собрать программу"
	@echo "  make clean            - Очистить временные файлы"
	@echo "  make run              - Запустить программу"
	@echo "  make docker-build     - Собрать Docker образ"
	@echo "  make docker-run       - Запустить в Docker"
	@echo "  make docker-dev       - Запустить интерактивную оболочку Docker"
	@echo "  make docker-clean     - Удалить Docker образ"
	@echo "  make docker-build-small - Собрать оптимизированный Docker образ"
	@echo "  make docker-run-small - Запустить оптимизированный контейнер"
	@echo "  make docker-size      - Показать размеры Docker образов"
	@echo "  make help             - Показать эту справку"

# Проверка наличия Docker
docker-check:
	@command -v docker >/dev/null 2>&1 || { echo "❌ Docker не установлен"; exit 1; }
	@echo "✅ Docker установлен"

# Зависимость для docker-run
docker-run: docker-check