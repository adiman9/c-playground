#include <stdio.h>

float fahrenheitToCelcius(int fahr);

/* print Fahrenheit-Celcius table
 * for fahr = 0, 20, ..., 300; using a function */
int main() {
  float fahr, celcius;
  int lower, upper, step;

  lower = 0;    /* lower limit of temperature table */
  upper = 300;  /* upper limit */
  step = 20;    /* step size */

  fahr = lower;
  while (fahr <= upper) {
    celcius = fahrenheitToCelcius(fahr);
    printf("%3.0f %6.1f\n", fahr, celcius);
    fahr = fahr + step;
  }
  return 0;
}

float fahrenheitToCelcius(int fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}
