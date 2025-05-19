/*Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing.*/

#include <stdio.h>

char daytab[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *first = &daytab[1];

int day_of_year(int year, int month, int day) {
  int leap;
  leap = (year%4 == 0 && year%100 != 0 || year%400 == 0);
  for (char *p = first; p < first + (month - 1); p++)
    day += *p;
  return (month > 2)? day + leap: day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap;
  char *p;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (p = first; yearday > *p; p++)
    yearday -= ((p == first + 1) && leap)? *p - 1: *p;
  *pmonth = (p - first);
  *pday = yearday;
}
