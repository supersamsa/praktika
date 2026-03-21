# Используем официальный образ GCC
FROM gcc:latest

# Информация о создателе
LABEL maintainer="Student"
LABEL description="Лабораторная работа №2 - Битовые поля и операции"

# Устанавливаем рабочий каталог
WORKDIR /app

# Копируем все исходные файлы из корня проекта
COPY *.c *.h ./

# Копируем Makefile из директории build
COPY build/Makefile ./Makefile

# Показываем содержимое для отладки
RUN echo "📁 Содержимое директории:" && ls -la

# Компилируем программу
RUN echo "🔨 Компиляция программы..." && \
    make clean && \
    make all && \
    echo "✅ Компиляция завершена"

# Проверяем что исполняемый файл создан
RUN test -f /app/lab2_program && \
    echo "✅ Исполняемый файл создан в /app/lab2_program" || \
    echo "❌ Исполняемый файл не найден"

# Запускаем программу по умолчанию
CMD ["./lab2_program"]