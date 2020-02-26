#include <stdio.h>

int main() {
  int c, nl, tc, bc;

  bc = 0;
  nl = 0;
  tc = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ') {
      ++bc;
    } else if (c == '\t') {
      ++tc;
    } else if (c == '\n') {
      ++nl;
    }
  }

  printf("blanks: %d\ntabs: %d\nnew lines: %d\n", bc, tc, nl);

  return 0;
}
