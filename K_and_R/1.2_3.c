#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = -20;
  upper = 150;
  step = 10;

  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius / (5.0 / 9.0)) + 32.0; 
    printf("%6.1f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
