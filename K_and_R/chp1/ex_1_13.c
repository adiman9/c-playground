#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

/* histogram of word lengths */
int main() {
  int c, i, j, state, wcount;
  int wlength[20];
  state = OUT;
  wcount = 0;

  for (i = 0; i < 20; ++i) {
    wlength[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++wlength[wcount];
      }
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      wcount = 1;
    } else {
      ++wcount;
    }
  }

  printf("Word length occurences:\n");
  for (i = 0; i < 20; ++i) {
    printf("%d:\t", i);
    for (j = 0; j < wlength[i]; ++j) {
      printf(" |");
    }
    printf("\n");
  }
  return 0;
}
