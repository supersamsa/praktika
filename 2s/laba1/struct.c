#include "struct.h"

int isValidDate(int d, int m, int y, int h, int min) {
  if (d < 1 || m < 1 || m > 12 || y < 0 || h < 0 || h > 23 || min < 0 ||
      min > 59)
    return 0;
  int days_in_month;

  if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
    days_in_month = 31;
  } else if (m == 4 || m == 6 || m == 9 || m == 11) {
    days_in_month = 30;
  } else {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
      days_in_month = 29;
    } else {
      days_in_month = 28;
    }
  }
  if (d > days_in_month)
    return 0;

  return 1;
}
datetime *datetimeDefault() {}
datetime *datetimeCreate(int day, int month, int year, int hour, int minute);
datetime *datetimeCopy(const datetime *src);
void datetimeFree(datetime *dt);