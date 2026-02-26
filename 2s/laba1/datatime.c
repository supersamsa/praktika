#include "datatime.h"

int dateTimeIsLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dateTimeDaysInMonth(int month, int year) {
  if (month < 1 || month > 12)
    return 0;

  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && dateTimeIsLeapYear(year)) {
    return 29;
  }
  return days[month - 1];
}

int dateTimeIsValid(int day, int month, int year, int hour, int minute) {
  if (year < 1970 || year > 2100)
    return 0;
  if (month < 1 || month > 12)
    return 0;
  if (day < 1 || day > dateTimeDaysInMonth(month, year))
    return 0;
  if (hour < 0 || hour > 23)
    return 0;
  if (minute < 0 || minute > 59)
    return 0;
  return 1;
}

DateTime *dateTimeCreate(int day, int month, int year, int hour, int minute) {
  if (!dateTimeIsValid(day, month, year, hour, minute)) {
    printf("EREREREORR\n");
    return NULL;
  }

  DateTime *dt = (DateTime *)malloc(sizeof(DateTime));
  if (!dt)
    return NULL;

  dt->day = (int *)malloc(sizeof(int));
  dt->month = (int *)malloc(sizeof(int));
  dt->year = (int *)malloc(sizeof(int));
  dt->hour = (int *)malloc(sizeof(int));
  dt->minute = (int *)malloc(sizeof(int));

  if (!dt->day || !dt->month || !dt->year || !dt->hour || !dt->minute) {
    free(dt->day);
    free(dt->month);
    free(dt->year);
    free(dt->hour);
    free(dt->minute);
    free(dt);
    return NULL;
  }

  *dt->day = day;
  *dt->month = month;
  *dt->year = year;
  *dt->hour = hour;
  *dt->minute = minute;

  printf("Конструктор dateTimeCreate вызван: %02d.%02d.%04d %02d:%02d\n", day,
         month, year, hour, minute);
  return dt;
}

DateTime *dateTimeCreateDefault(void) {
  time_t t = time(NULL);
  struct tm *tmInfo = localtime(&t);

  DateTime *dt =
      dateTimeCreate(tmInfo->tm_mday, tmInfo->tm_mon + 1,
                     tmInfo->tm_year + 1900, tmInfo->tm_hour, tmInfo->tm_min);

  printf("Конструктор по умолчанию вызван\n");
  return dt;
}

DateTime *dateTimeCopy(const DateTime *other) {
  if (!other)
    return NULL;

  DateTime *dt = dateTimeCreate(*other->day, *other->month, *other->year,
                                *other->hour, *other->minute);

  printf("Копирующий конструктор вызван\n");
  return dt;
}

void dateTimeDestroy(DateTime *dt) {
  if (dt) {
    printf("Деструктор вызван для: %02d.%02d.%04d %02d:%02d\n", *dt->day,
           *dt->month, *dt->year, *dt->hour, *dt->minute);

    free(dt->day);
    free(dt->month);
    free(dt->year);
    free(dt->hour);
    free(dt->minute);
    free(dt);
  }
}

int dateTimeEqual(const DateTime *dt1, const DateTime *dt2) {
  if (!dt1 || !dt2)
    return 0;
  return (*dt1->year == *dt2->year && *dt1->month == *dt2->month &&
          *dt1->day == *dt2->day && *dt1->hour == *dt2->hour &&
          *dt1->minute == *dt2->minute)
             ? 1
             : 0;
}

int dateTimeNotEqual(const DateTime *dt1, const DateTime *dt2) {
  return !dateTimeEqual(dt1, dt2);
}

int dateTimeGreater(const DateTime *dt1, const DateTime *dt2) {
  if (!dt1 || !dt2)
    return 0;

  if (*dt1->year != *dt2->year)
    return (*dt1->year > *dt2->year) ? 1 : 0;
  if (*dt1->month != *dt2->month)
    return (*dt1->month > *dt2->month) ? 1 : 0;
  if (*dt1->day != *dt2->day)
    return (*dt1->day > *dt2->day) ? 1 : 0;
  if (*dt1->hour != *dt2->hour)
    return (*dt1->hour > *dt2->hour) ? 1 : 0;
  return (*dt1->minute > *dt2->minute) ? 1 : 0;
}

int dateTimeLess(const DateTime *dt1, const DateTime *dt2) {
  return (!dateTimeGreater(dt1, dt2) && !dateTimeEqual(dt1, dt2)) ? 1 : 0;
}

int dateTimeGreaterOrEqual(const DateTime *dt1, const DateTime *dt2) {
  return (dateTimeGreater(dt1, dt2) || dateTimeEqual(dt1, dt2)) ? 1 : 0;
}

int dateTimeLessOrEqual(const DateTime *dt1, const DateTime *dt2) {
  return (dateTimeLess(dt1, dt2) || dateTimeEqual(dt1, dt2)) ? 1 : 0;
}

void dateTimePrint(const DateTime *dt) {
  if (dt) {
    printf("%02d.%02d.%04d %02d:%02d", *dt->day, *dt->month, *dt->year,
           *dt->hour, *dt->minute);
  }
}

void dateTimePrintField(const DateTime *dt, const char *field) {
  if (!dt)
    return;

  if (strcmp(field, "day") == 0)
    printf("%02d", *dt->day);
  else if (strcmp(field, "month") == 0)
    printf("%02d", *dt->month);
  else if (strcmp(field, "year") == 0)
    printf("%04d", *dt->year);
  else if (strcmp(field, "hour") == 0)
    printf("%02d", *dt->hour);
  else if (strcmp(field, "minute") == 0)
    printf("%02d", *dt->minute);
  else
    printf("Nan");
}

void dateTimeInput(DateTime *dt) {
  if (!dt)
    return;

  int d, m, y, h, min;
  printf("Введите дату и время (день месяц год часы минуты): ");
  scanf("%d %d %d %d %d", &d, &m, &y, &h, &min);

  if (dateTimeIsValid(d, m, y, h, min)) {
    *dt->day = d;
    *dt->month = m;
    *dt->year = y;
    *dt->hour = h;
    *dt->minute = min;
  } else {
    printf("ERERER\n");
  }
}

void dateTimeInputField(DateTime *dt, const char *field) {
  if (!dt)
    return;

  int value;
  printf("Введите значение для поля %s: ", field);
  scanf("%d", &value);

  if (strcmp(field, "day") == 0)
    dateTimeSetDay(dt, value);
  else if (strcmp(field, "month") == 0)
    dateTimeSetMonth(dt, value);
  else if (strcmp(field, "year") == 0)
    dateTimeSetYear(dt, value);
  else if (strcmp(field, "hour") == 0)
    dateTimeSetHour(dt, value);
  else if (strcmp(field, "minute") == 0)
    dateTimeSetMinute(dt, value);
  else
    printf("Неизвестное поле\n");
}

void dateTimeIncrementDay(DateTime *dt) {
  if (!dt)
    return;

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

void dateTimeDecrementDay(DateTime *dt) {
  if (!dt)
    return;

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

void dateTimeSetDay(DateTime *dt, int day) {
  if (!dt)
    return;
  if (day >= 1 && day <= dateTimeDaysInMonth(*dt->month, *dt->year)) {
    *dt->day = day;
  } else {
    printf("ererer\n");
  }
}

void dateTimeSetMonth(DateTime *dt, int month) {
  if (!dt)
    return;
  if (month >= 1 && month <= 12) {
    *dt->month = month;
    if (*dt->day > dateTimeDaysInMonth(*dt->month, *dt->year)) {
      *dt->day = dateTimeDaysInMonth(*dt->month, *dt->year);
    }
  } else {
    printf("ererer\n");
  }
}

void dateTimeSetYear(DateTime *dt, int year) {
  if (!dt)
    return;
  if (year >= 1970 && year <= 2100) {
    *dt->year = year;
    if (*dt->day > dateTimeDaysInMonth(*dt->month, *dt->year)) {
      *dt->day = dateTimeDaysInMonth(*dt->month, *dt->year);
    }
  } else {
    printf("ererreror\n");
  }
}

void dateTimeSetHour(DateTime *dt, int hour) {
  if (!dt)
    return;
  if (hour >= 0 && hour <= 23) {
    *dt->hour = hour;
  } else {
    printf("ereorero\n");
  }
}

void dateTimeSetMinute(DateTime *dt, int minute) {
  if (!dt)
    return;
  if (minute >= 0 && minute <= 59) {
    *dt->minute = minute;
  } else {
    printf("ererpepr\n");
  }
}

void dateTimePrintFormatted(const DateTime *dt, const char *format) {
  if (!dt)
    return;

  char buffer[256];
  char *ptr = buffer;

  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%' && format[i + 1] != '\0') {
      i++;
      switch (format[i]) {
      case 'd':
        ptr += sprintf(ptr, "%02d", *dt->day);
        break;
      case 'm':
        ptr += sprintf(ptr, "%02d", *dt->month);
        break;
      case 'Y':
        ptr += sprintf(ptr, "%04d", *dt->year);
        break;
      case 'H':
        ptr += sprintf(ptr, "%02d", *dt->hour);
        break;
      case 'M':
        ptr += sprintf(ptr, "%02d", *dt->minute);
        break;
      default:
        *ptr++ = format[i - 1];
        *ptr++ = format[i];
        break;
      }
    } else {
      *ptr++ = format[i];
    }
  }
  *ptr = '\0';
  printf("%s", buffer);
}

void dateTimeInputFormatted(DateTime *dt, const char *format) {
  if (!dt)
    return;

  char input[256];
  printf("input format %s: ", format);
  scanf("%s", input);

  int d = *dt->day, m = *dt->month, y = *dt->year, h = *dt->hour,
      min = *dt->minute;
  char *ptr = input;
  int value;

  for (int i = 0; format[i] != '\0' && *ptr != '\0'; i++) {
    if (format[i] == '%' && format[i + 1] != '\0') {
      i++;
      switch (format[i]) {
      case 'd':
        if (sscanf(ptr, "%2d", &value) == 1) {
          d = value;
          ptr += 2;
        }
        break;
      case 'm':
        if (sscanf(ptr, "%2d", &value) == 1) {
          m = value;
          ptr += 2;
        }
        break;
      case 'Y':
        if (sscanf(ptr, "%4d", &value) == 1) {
          y = value;
          ptr += 4;
        }
        break;
      case 'H':
        if (sscanf(ptr, "%2d", &value) == 1) {
          h = value;
          ptr += 2;
        }
        break;
      case 'M':
        if (sscanf(ptr, "%2d", &value) == 1) {
          min = value;
          ptr += 2;
        }
        break;
      default:
        if (*ptr == format[i])
          ptr++;
        break;
      }
    } else if (*ptr == format[i]) {
      ptr++;
    } else {
      ptr++;
    }
  }

  if (dateTimeIsValid(d, m, y, h, min)) {
    *dt->day = d;
    *dt->month = m;
    *dt->year = y;
    *dt->hour = h;
    *dt->minute = min;
  } else {
    printf("ererere\n");
  }
}

void dateTimeInterval(const DateTime *dt1, const DateTime *dt2, int *years,
                      int *months, int *days, int *hours, int *minutes) {
  if (!dt1 || !dt2)
    return;

  *years = abs(*dt1->year - *dt2->year);
  *months = abs(*dt1->month - *dt2->month);
  *days = abs(*dt1->day - *dt2->day);
  *hours = abs(*dt1->hour - *dt2->hour);
  *minutes = abs(*dt1->minute - *dt2->minute);
}

long long dateTimeToUnixTimestamp(const DateTime *dt) {
  if (!dt)
    return -1;

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