#include <stdio.h>

/* Same example as previous but using floats instead 
 * to gain more accuracy */
int main () {
  float fahr, celsius;
  float lower, upper, step;
  printf("\nTemperature conversion Fahr -> Celsius:\n\n");

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    /* this time explicit floats are used to avoid 
     * integer division truncation */
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}

/* printf also recognises the following formating:
 *
 * %d: decimal
 * %f: float
 * %o: octal
 * %x: hex
 * %c: character
 * %s: character string
 * %%: itself
 *
 */
