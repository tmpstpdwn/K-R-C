/*Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define DOUBLE "12.3243123243235"

double atof(char s[]) {
  double val, power;
  int i, sign;
  int e, esign;

  for (i = 0; isspace(s[i]); i++);

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  // Before .
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  // After .
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  // e
  if (s[i] == 'e') {
    i++;
  }
  esign = (s[i] == '-')? -1: 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (e = 0; isdigit(s[i]); i++)
    e = 0 * e + (s[i] - '0');
  e = pow(10, e);

  // power
  power = (esign < 0)? power * e: power / e;

  return sign * (val / power);
}

int main() {
  char x[] = DOUBLE;
  double y = atof(x);
  printf("%f\n", y);
  return 0;
}
