#ifndef SRUCT_H
#define SRUCT_H

#include "stdio.h"

typedef struct {
  int *minute;
  int *hour;
  int *day;
  int *month;
  int *year;
} datetime;

datetime *datetimeDefault();
datetime *datetimeCreate(int day, int month, int year, int hour, int minute);
datetime *datetimeCopy(const datetime *src);
void datetimeFree(datetime *dt);
int isValidDate(datetime *dt);

#endif