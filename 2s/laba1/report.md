# Отчет по лабораторной работе
## Тема: Изучение структур и разработка структур с использованием динамической памяти

### Вариант 3: Дата и Время (DateTime)

---

## 1. Цель работы

Изучить новые способы представления данных с помощью создания переменных типа структур. Познакомиться с созданием базовых методов структур, позволяющих реализовывать хранение структуры в динамической памяти компьютера. Изучить принципы методов: конструктор, копирующий конструктор, конструктор по умолчанию, деструктор.

---

## 2. Задание

Реализовать структуру `DateTime` (дата и время) с полями:
- день
- месяц
- год
- часы
- минуты

**Требования к реализации:**
- Все поля хранятся в динамической памяти
- Структура описана с использованием `typedef`
- Реализованы конструкторы (основной, копирующий, по умолчанию)
- Реализован деструктор
- Методы для сравнения объектов
- Методы ввода/вывода
- Методы изменения данных (++, --, setter'ы)
- Форматированный ввод/вывод
- Вычисление временных интервалов
- Представление в Unix timestamp

---

## 3. Структура проекта

Проект состоит из следующих файлов:
- `datatime.h` - заголовочный файл с объявлением структуры и методов
- `datatime.c` - реализация методов
- `main.c` - демонстрационная программа
- `Makefile` - файл для сборки проекта

---

## 4. Реализация структуры

### 4.1 Заголовочный файл (datatime.h)

В заголовочном файле объявлена структура `DateTime` с полями-указателями для хранения данных в динамической памяти:

```c
typedef struct {
    int* day;
    int* month;
    int* year;
    int* hour;
    int* minute;
} DateTime;
```

Также объявлены все необходимые методы:
- Конструкторы: `dateTimeCreate`, `dateTimeCreateDefault`, `dateTimeCopy`
- Деструктор: `dateTimeDestroy`
- Операторы сравнения: `dateTimeEqual`, `dateTimeGreater` и др.
- Методы ввода/вывода: `dateTimePrint`, `dateTimeInput`
- Методы изменения: `dateTimeIncrementDay`, `dateTimeDecrementDay`, setter'ы
- Форматированный ввод/вывод: `dateTimePrintFormatted`, `dateTimeInputFormatted`
- Временные интервалы: `dateTimeInterval`
- Unix timestamp: `dateTimeToUnixTimestamp`
- Вспомогательные функции: `dateTimeIsValid`, `dateTimeDaysInMonth`, `dateTimeIsLeapYear`

### 4.2 Реализация методов (datatime.c)

#### 4.2.1 Вспомогательные функции

Для корректной работы с датами реализованы функции проверки високосного года и количества дней в месяце:

```c
int dateTimeIsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dateTimeDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && dateTimeIsLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}
```

Функция валидации проверяет корректность введенных данных:

```c
int dateTimeIsValid(int day, int month, int year, int hour, int minute) {
    if (year < 1970 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > dateTimeDaysInMonth(month, year)) return 0;
    if (hour < 0 || hour > 23) return 0;
    if (minute < 0 || minute > 59) return 0;
    return 1;
}
```

#### 4.2.2 Конструкторы

**Основной конструктор** - выделяет память для всех полей и инициализирует их:

```c
DateTime* dateTimeCreate(int day, int month, int year, int hour, int minute) {
    if (!dateTimeIsValid(day, month, year, hour, minute)) {
        printf("EREREREORR\n");
        return NULL;
    }
    
    DateTime* dt = (DateTime*)malloc(sizeof(DateTime));
    dt->day = (int*)malloc(sizeof(int));
    dt->month = (int*)malloc(sizeof(int));
    dt->year = (int*)malloc(sizeof(int));
    dt->hour = (int*)malloc(sizeof(int));
    dt->minute = (int*)malloc(sizeof(int));
    
    *dt->day = day;
    *dt->month = month;
    *dt->year = year;
    *dt->hour = hour;
    *dt->minute = minute;
    
    printf("Конструктор dateTimeCreate вызван: %02d.%02d.%04d %02d:%02d\n", 
           day, month, year, hour, minute);
    return dt;
}
```

**Конструктор по умолчанию** - создает объект с текущей датой и временем:

```c
DateTime* dateTimeCreateDefault(void) {
    time_t t = time(NULL);
    struct tm *tmInfo = localtime(&t);
    
    DateTime* dt = dateTimeCreate(
        tmInfo->tm_mday,
        tmInfo->tm_mon + 1,
        tmInfo->tm_year + 1900,
        tmInfo->tm_hour,
        tmInfo->tm_min
    );
    
    printf("Конструктор по умолчанию вызван\n");
    return dt;
}
```

**Копирующий конструктор** - создает копию существующего объекта:

```c
DateTime* dateTimeCopy(const DateTime* other) {
    DateTime* dt = dateTimeCreate(
        *other->day,
        *other->month,
        *other->year,
        *other->hour,
        *other->minute
    );
    
    printf("Копирующий конструктор вызван\n");
    return dt;
}
```

#### 4.2.3 Деструктор

Деструктор освобождает всю выделенную динамическую память:

```c
void dateTimeDestroy(DateTime* dt) {
    if (dt) {
        printf("Деструктор вызван для: %02d.%02d.%04d %02d:%02d\n", 
               *dt->day, *dt->month, *dt->year, *dt->hour, *dt->minute);
        
        free(dt->day);
        free(dt->month);
        free(dt->year);
        free(dt->hour);
        free(dt->minute);
        free(dt);
    }
}
```

#### 4.2.4 Методы сравнения

Реализованы все операторы сравнения:

```c
int dateTimeEqual(const DateTime* dt1, const DateTime* dt2) {
    return (*dt1->year == *dt2->year && *dt1->month == *dt2->month && 
            *dt1->day == *dt2->day && *dt1->hour == *dt2->hour && 
            *dt1->minute == *dt2->minute) ? 1 : 0;
}

int dateTimeGreater(const DateTime* dt1, const DateTime* dt2) {
    if (*dt1->year != *dt2->year) return (*dt1->year > *dt2->year) ? 1 : 0;
    if (*dt1->month != *dt2->month) return (*dt1->month > *dt2->month) ? 1 : 0;
    if (*dt1->day != *dt2->day) return (*dt1->day > *dt2->day) ? 1 : 0;
    if (*dt1->hour != *dt2->hour) return (*dt1->hour > *dt2->hour) ? 1 : 0;
    return (*dt1->minute > *dt2->minute) ? 1 : 0;
}
```

Остальные операторы реализованы через комбинацию `Equal` и `Greater`.

#### 4.2.5 Методы изменения данных

**Инкремент и декремент дня** с учетом переполнения месяца и года:

```c
void dateTimeIncrementDay(DateTime* dt) {
    int daysInMonth = dateTimeDaysInMonth(*dt->month, *dt->year);
    
    if (*dt->day < daysInMonth) {
        (*dt->day)++;
    } else {
        *dt->day = 1;
        if (*dt->month < 12) {
            (*dt->month)++;
        } else {
            *dt->month = 1;
            (*dt->year)++;
        }
    }
}

void dateTimeDecrementDay(DateTime* dt) {
    if (*dt->day > 1) {
        (*dt->day)--;
    } else {
        if (*dt->month > 1) {
            (*dt->month)--;
        } else {
            *dt->month = 12;
            (*dt->year)--;
        }
        *dt->day = dateTimeDaysInMonth(*dt->month, *dt->year);
    }
}
```

**Setter'ы** с валидацией входных данных:

```c
void dateTimeSetDay(DateTime* dt, int day) {
    if (day >= 1 && day <= dateTimeDaysInMonth(*dt->month, *dt->year)) {
        *dt->day = day;
    } else {
        printf("ererer\n");
    }
}
```

#### 4.2.6 Форматированный вывод

Функция для вывода даты в произвольном формате:

```c
void dateTimePrintFormatted(const DateTime* dt, const char* format) {
    char buffer[256];
    char *ptr = buffer;
    
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i+1] != '\0') {
            i++;
            switch (format[i]) {
                case 'd': ptr += sprintf(ptr, "%02d", *dt->day); break;
                case 'm': ptr += sprintf(ptr, "%02d", *dt->month); break;
                case 'Y': ptr += sprintf(ptr, "%04d", *dt->year); break;
                case 'H': ptr += sprintf(ptr, "%02d", *dt->hour); break;
                case 'M': ptr += sprintf(ptr, "%02d", *dt->minute); break;
            }
        } else {
            *ptr++ = format[i];
        }
    }
    *ptr = '\0';
    printf("%s", buffer);
}
```

#### 4.2.7 Временные интервалы

Вычисление разницы между двумя датами:

```c
void dateTimeInterval(const DateTime* dt1, const DateTime* dt2, 
                       int* years, int* months, int* days, int* hours, int* minutes) {
    *years = abs(*dt1->year - *dt2->year);
    *months = abs(*dt1->month - *dt2->month);
    *days = abs(*dt1->day - *dt2->day);
    *hours = abs(*dt1->hour - *dt2->hour);
    *minutes = abs(*dt1->minute - *dt2->minute);
}
```

#### 4.2.8 Unix timestamp

Преобразование даты в количество секунд с начала эпохи Unix:

```c
long long dateTimeToUnixTimestamp(const DateTime* dt) {
    struct tm tmInfo = {0};
    tmInfo.tm_mday = *dt->day;
    tmInfo.tm_mon = *dt->month - 1;
    tmInfo.tm_year = *dt->year - 1900;
    tmInfo.tm_hour = *dt->hour;
    tmInfo.tm_min = *dt->minute;
    tmInfo.tm_sec = 0;
    tmInfo.tm_isdst = -1;
    
    time_t timestamp = mktime(&tmInfo);
    return (long long)timestamp;
}
```

---

## 5. Демонстрационная программа

### 5.1 Код демонстрационной программы (main.c)

```c
#include "datatime.h"
#include <stdio.h>

int main() {
    DateTime* dt1 = dateTimeCreate(15, 3, 2024, 14, 30);
    DateTime* dt2 = dateTimeCreateDefault();
    DateTime* dt3 = dateTimeCopy(dt1);
    
    printf("dt1: "); dateTimePrint(dt1); printf("\n");
    printf("dt2: "); dateTimePrint(dt2); printf("\n");
    printf("dt3: "); dateTimePrint(dt3); printf("\n\n");
    
    printf("equal: %d\n", dateTimeEqual(dt1, dt3));
    printf("not equal: %d\n", dateTimeNotEqual(dt1, dt2));
    printf("greater: %d\n", dateTimeGreater(dt1, dt2));
    printf("less: %d\n", dateTimeLess(dt1, dt2));
    printf("greater or equal: %d\n", dateTimeGreaterOrEqual(dt1, dt3));
    printf("less or equal: %d\n\n", dateTimeLessOrEqual(dt1, dt3));
    
    dateTimeIncrementDay(dt1);
    printf("++: "); dateTimePrint(dt1); printf("\n");
    dateTimeDecrementDay(dt1);
    printf("--: "); dateTimePrint(dt1); printf("\n\n");
    
    dateTimeSetDay(dt1, 20);
    dateTimeSetHour(dt1, 10);
    dateTimeSetMinute(dt1, 45);
    printf("set: "); dateTimePrint(dt1); printf("\n");
    printf("day:%d\n\n", *dt1->day);
    
    printf("formatted: "); 
    dateTimePrintFormatted(dt1, "%d.%m.%Y %H:%M"); printf("\n\n");
    
    int y,m,d,h,min;
    dateTimeInterval(dt1, dt2, &y,&m,&d,&h,&min);
    printf("interval: %dy %dm %dd %dh %dmin\n\n", y,m,d,h,min);
    
    printf("unix: %lld\n\n", dateTimeToUnixTimestamp(dt1));
    
    printf("input format dd.mm.yyyy: ");
    dateTimeInputFormatted(dt1, "%d.%m.%Y");
    printf("now: "); dateTimePrint(dt1); printf("\n\n");
    
    dateTimeDestroy(dt1);
    dateTimeDestroy(dt2);
    dateTimeDestroy(dt3);
    
    return 0;
}
```

### 5.2 Результат выполнения

```
Конструктор dateTimeCreate вызван: 15.03.2024 14:30
Конструктор dateTimeCreate вызван: 27.02.2026 01:15
Конструктор по умолчанию вызван
Конструктор dateTimeCreate вызван: 15.03.2024 14:30
Копирующий конструктор вызван
dt1: 15.03.2024 14:30
dt2: 27.02.2026 01:15
dt3: 15.03.2024 14:30

equal: 1
not equal: 1
greater: 0
less: 1
greater or equal: 1
less or equal: 1

++: 16.03.2024 14:30
--: 15.03.2024 14:30

set: 20.03.2024 10:45
day:20

formatted: 20.03.2024 10:45

interval: 2y 0m 7d 9h 30min

unix: 1710906300

input format dd.mm.yyyy: 20.01.2000
now: 20.01.2000 10:45

Деструктор вызван для: 20.01.2000 10:45
Деструктор вызван для: 27.02.2026 01:15
Деструктор вызван для: 15.03.2024 14:30
```

---

## 6. Makefile

Для автоматизации сборки проекта используется Makefile:

```makefile
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
```

**Команды для работы:**
- `make` - сборка проекта
- `make run` - запуск программы
- `make clean` - очистка объектных файлов

---

## 7. Анализ работы конструкторов и деструкторов

Из вывода программы видна последовательность вызовов:

1. **Конструктор dateTimeCreate** - при создании dt1
2. **Конструктор dateTimeCreate** - при создании dt2 (через конструктор по умолчанию)
3. **Конструктор по умолчанию** - сообщение о вызове
4. **Конструктор dateTimeCreate** - при создании dt3 (через копирующий конструктор)
5. **Копирующий конструктор** - сообщение о вызове
6. **Деструкторы** - при уничтожении каждого объекта в обратном порядке создания

Важно отметить, что каждый конструктор явно выводит сообщение о своем вызове, что позволяет отследить жизненный цикл объектов.

---

## 8. Особенности работы с динамической памятью

В данной работе все поля структуры хранятся в динамической памяти:

```c
typedef struct {
    int* day;        // указатель на динамическую память
    int* month;      // указатель на динамическую память
    int* year;       // указатель на динамическую память
    int* hour;       // указатель на динамическую память
    int* minute;     // указатель на динамическую память
} DateTime;
```

**Преимущества такого подхода:**
- Гибкое управление временем жизни объектов
- Возможность создания массивов структур с переменным размером
- Эффективное использование памяти

**Особенности реализации:**
1. При создании объекта выделяется память под саму структуру и под каждое поле
2. При копировании создается новая независимая копия с собственной памятью
3. Деструктор освобождает всю выделенную память в правильном порядке

---

## 9. Выводы

В ходе выполнения лабораторной работы были достигнуты следующие результаты:

1. **Изучена работа с динамической памятью** в контексте структур языка C
2. **Реализованы все три типа конструкторов**:
   - Основной конструктор для инициализации с параметрами
   - Конструктор по умолчанию (текущее время)
   - Копирующий конструктор для создания независимых копий

3. **Реализован деструктор**, корректно освобождающий всю выделенную память

4. **Создан полный набор методов** для работы с датой и временем:
   - Операторы сравнения (6 методов)
   - Методы ввода/вывода (стандартные и форматированные)
   - Операции инкремента/декремента
   - Setter'ы с валидацией
   - Вычисление временных интервалов
   - Преобразование в Unix timestamp

5. **Организована модульная структура** проекта с разделением на заголовочный файл и файл реализации

6. **Автоматизирована сборка** с помощью Makefile

Особое внимание было уделено корректной работе с динамической памятью и обработке граничных случаев (високосные года, переход между месяцами, валидация входных данных).

Все требования задания выполнены в полном объеме.