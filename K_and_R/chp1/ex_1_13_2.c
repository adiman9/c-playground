#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */
#define SLOTS 20 /* number of word length slots */

/* vertical bar histogram of word length */
int main() {
  int c, i, row, state, wcount, max;
  int wlength[SLOTS];
  state = OUT;
  wcount = 0;

  for (i = 0; i < SLOTS; ++i) {
    wlength[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++wlength[wcount];
      }
      state = OUT;
      wcount = 0;
    } else if (state == OUT) {
      state = IN;
      wcount = 1;
    } else {
      ++wcount;
    }
  }

  max = 0;
  for (i = 0; i < SLOTS; ++i) {
    if (wlength[i] > max) {
      max = wlength[i];
    }
  }

  printf("Word length occurences:\n");

  for (row = max; row > 0; --row) {
    for (i = 0; i < SLOTS; ++i) {
      if (wlength[i] >= row) {
        printf("__");
      }
      printf("\t");
    }
    printf("\n");
  }

  for (i = 0; i < SLOTS; ++i) {
    printf("%d\t", i);
  }
  printf("\n");

  return 0;
}
