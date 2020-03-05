#include <stdio.h>

#define MAXLINE 1000  /* maximum trailing whitespace */
#define IN  1
#define OUT 0

/* remove trailing whitespace and blank lines */
int main() {
  int c;
  int i;
  int head, tail, dirty;   /* head and tail of search */
  int state;
  int whitespace[MAXLINE];   /* current input line */

  for (i = 0; i < MAXLINE; ++i) {
    whitespace[i] = 0;
  }

  head = 0;
  tail = 0;
  dirty = OUT;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (head >= MAXLINE) {
      /* too many whitespace characters */
      return 1;
    }
    if (c == '\n') {
      if (dirty == IN) {
        putchar(c);
      }
      head = 0;
      tail = 0;
      dirty = OUT;
    } else if (c == ' ' || c == '\t') {
      whitespace[head] = c;
      ++head;
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      while (tail < head) {
        putchar(whitespace[tail]);
        ++tail;
      }
      putchar(c);
      dirty = IN;
      head = 0;
      tail = 0;
    } else {
      putchar(c);
    }
  }

  return 0;
}
