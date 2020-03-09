#include <stdio.h>

#define MAXLENGTH 1000

void reverse(char line[]);
int getnextline(char line[], int lim);

int main() {
  int len;
  char line[MAXLENGTH];

  while ((len = getnextline(line, MAXLENGTH)) > 0) {
    reverse(line);
  }
  printf("%d", len);
  return 0;
}

void reverse(char line[]) {
  int i;
  for (i = 0; line[i] != '\0'; ++i) {
    ;
  }

  --i;

  for (; i >= 0; --i) {
    putchar(line[i]);
  }
  putchar('\n');
}

int getnextline(char line[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  return i;
}
