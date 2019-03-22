/* code: c1-3.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

struct Student {
  int id;
  char grade;
  float average;
};
typedef struct Student STUDENT_TYPE;

int main () {
  STUDENT_TYPE a[5];
  int i;

  a[0].id = 100;
  a[0].grade = 'A';
  a[0].average = 510.20;

  a[1].id = 101;
  a[1].grade = 'C';
  a[1].average = 350.00;

  a[2].id = 105;
  a[2].grade = 'B';
  a[2].average = 450.50;

  for (i = 0; i < 3; i++) {
    printf ("%d ", a[i].id);
    printf ("%c ", a[i].grade);
    printf ("%2.2f\n", a[i].average);
  }

  return 0;
}
