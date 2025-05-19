//Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.

#include <stdio.h>

static char daytab[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = (year%4 == 0 && year%100 != 0 || year%400 == 0);
  for (i = 1; i < month; i++)
    day += daytab[i];
  return (month > 2)? day + leap: day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > daytab[i]; i++)
    yearday = ((i == 2) && leap)?  yearday - (daytab[i] + 1): yearday - daytab[i];
  *pmonth = i;
  *pday = yearday;
}
