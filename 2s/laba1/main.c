#include "datatime.h"
#include <stdio.h>

int main() {
  DateTime *dt1 = dateTimeCreate(15, 3, 2024, 14, 30);
  DateTime *dt2 = dateTimeCreateDefault();
  DateTime *dt3 = dateTimeCopy(dt1);

  printf("dt1: ");
  dateTimePrint(dt1);
  printf("\n");
  printf("dt2: ");
  dateTimePrint(dt2);
  printf("\n");
  printf("dt3: ");
  dateTimePrint(dt3);
  printf("\n\n");

  printf("equal: %d\n", dateTimeEqual(dt1, dt3));
  printf("not equal: %d\n", dateTimeNotEqual(dt1, dt2));
  printf("greater: %d\n", dateTimeGreater(dt1, dt2));
  printf("less: %d\n", dateTimeLess(dt1, dt2));
  printf("greater or equal: %d\n", dateTimeGreaterOrEqual(dt1, dt3));
  printf("less or equal: %d\n\n", dateTimeLessOrEqual(dt1, dt3));

  dateTimeIncrementDay(dt1);
  printf("++: ");
  dateTimePrint(dt1);
  printf("\n");
  dateTimeDecrementDay(dt1);
  printf("--: ");
  dateTimePrint(dt1);
  printf("\n\n");

  dateTimeSetDay(dt1, 20);
  dateTimeSetHour(dt1, 10);
  dateTimeSetMinute(dt1, 45);
  printf("set: ");
  dateTimePrint(dt1);
  printf("\n");
  printf("day:%d\n\n", *dt1->day);

  printf("formatted: ");
  dateTimePrintFormatted(dt1, "%d.%m.%Y %H:%M");
  printf("\n\n");

  int y, m, d, h, min;
  dateTimeInterval(dt1, dt2, &y, &m, &d, &h, &min);
  printf("interval: %dy %dm %dd %dh %dmin\n\n", y, m, d, h, min);

  printf("unix: %lld\n\n", dateTimeToUnixTimestamp(dt1));

 // dateTimeInputFormatted(dt1, "%d.%m.%Y");
 // printf("now: ");
 // dateTimePrint(dt1);
 // printf("\n\n");

  dateTimeDestroy(dt1);
  dateTimeDestroy(dt2);
  dateTimeDestroy(dt3);

  return 0;
}