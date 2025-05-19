// INCLUDES.
#include <stdlib.h>
#include <ctype.h>
#include "util.h"

// Swap i'th, j'th elements in v.
static void swap(void **v, int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// Compare numerically by field if provided or by entire line.
int numcmp(const char *s1, const char *s2, int field) {
  double v1, v2;

  if (field) {
    const char *p1 = fieldpointer(s1, field);
    const char *p2 = fieldpointer(s2, field);
    if (!p1) {
      return -1;
    }
    if (!p2) {
      return 0;
    }
    v1 = atof(p1);
    v2 = atof(p2);
  } else {
    v1 = atof(s1);
    v2 = atof(s2);
  }

  if (v1 < v2)
    return -1;
  else
    return 0;
}

// Compare lexigraphically by field if provided or by entire line.
int strcmpnorm(const char *s1, const char *s2, int field) {
  int minlen = 0, i = 0;

  if (field) {
    s1 = fieldpointer(s1, field);
    s2 = fieldpointer(s2, field);
    if (!s1) {
      return -1;
    }
    if (!s2) {
      return 0;
    }
    int l1 = fieldlen(s1);
    int l2 = fieldlen(s2);
    minlen = (l1 < l2)? l1: l2;
  }

  while (*s1 != '\0' && *s1 == *s2) {
    if (minlen && i >= minlen) {
      break;
    }
    i++;
    s1++;
    s2++;
  }

  return *s1 - *s2;
}

// Compare lexigraphically and case insensitively by field if provided or by entire line.
int strcmplow(const char *s1, const char *s2, int field) {
  int minlen = 0, i = 0;

  if (field) {
    s1 = fieldpointer(s1, field);
    s2 = fieldpointer(s2, field);
    if (!s1) {
      return -1;
    }
    if (!s2) {
      return 0;
    }
    int l1 = fieldlen(s1);
    int l2 = fieldlen(s2);
    minlen = (l1 < l2)? l1: l2;
  }

  while (*s1 != '\0' && tolower(*s1) == tolower(*s2)) {
    if (minlen && i >= minlen) {
      break;
    }
    i++;
    s1++;
    s2++;
  }

  return tolower(*s1) - tolower(*s2);
}

// Quicksort lines of v by field if provided or by entire line using selected comparison operation.
void qsortc(void **v, int left, int right, int (*comp)(void *, void *, int), int field) {
  int i, last;
  if (left >= right)
    return;
  last = left + 1;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left], field) < 0)
      swap(v, last++, i);
  swap(v, left, last-1);
  qsortc(v, left, last-2, comp, field);
  qsortc(v, last, right, comp, field);
}
