#ifndef DATATIME_H
#define DATATIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int *day;
  int *month;
  int *year;
  int *hour;
  int *minute;
} DateTime;

DateTime *dateTimeCreate(int day, int month, int year, int hour, int minute);
DateTime *dateTimeCreateDefault(void);
DateTime *dateTimeCopy(const DateTime *other);

void dateTimeDestroy(DateTime *dt);

int dateTimeEqual(const DateTime *dt1, const DateTime *dt2);
int dateTimeNotEqual(const DateTime *dt1, const DateTime *dt2);
int dateTimeGreater(const DateTime *dt1, const DateTime *dt2);
int dateTimeLess(const DateTime *dt1, const DateTime *dt2);
int dateTimeGreaterOrEqual(const DateTime *dt1, const DateTime *dt2);
int dateTimeLessOrEqual(const DateTime *dt1, const DateTime *dt2);

void dateTimePrint(const DateTime *dt);
void dateTimePrintField(const DateTime *dt, const char *field);
void dateTimeInput(DateTime *dt);
void dateTimeInputField(DateTime *dt, const char *field);

void dateTimeIncrementDay(DateTime *dt);
void dateTimeDecrementDay(DateTime *dt);
void dateTimeSetDay(DateTime *dt, int day);
void dateTimeSetMonth(DateTime *dt, int month);
void dateTimeSetYear(DateTime *dt, int year);
void dateTimeSetHour(DateTime *dt, int hour);
void dateTimeSetMinute(DateTime *dt, int minute);

void dateTimePrintFormatted(const DateTime *dt, const char *format);
void dateTimeInputFormatted(DateTime *dt, const char *format);

void dateTimeInterval(const DateTime *dt1, const DateTime *dt2, int *years,
                      int *months, int *days, int *hours, int *minutes);

long long dateTimeToUnixTimestamp(const DateTime *dt);

int dateTimeIsValid(int day, int month, int year, int hour, int minute);
int dateTimeDaysInMonth(int month, int year);
int dateTimeIsLeapYear(int year);

#endif