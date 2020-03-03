#include <stdio.h>

#define MAXLINE 1000  /* maximum input line size */

int getnextlinelength(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
  int c;
  int len;  /* current line length */
  int max;  /* maximum length seen so far */
  char line[MAXLINE];   /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;

  while ((len = getnextlinelength(line, MAXLINE)) > 0) {
    /* Line maxed out array. Keep going to find actual end of line */
    if (len == MAXLINE - 1) {
      while ((c = getchar()) != EOF && c != '\n') {
        ++len;
      }
    }
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {  /* there was a line */
    printf("%s is %d characters long", longest, max);
  }
  return 0;
}

/* getnextlinelength: read a line into s, return length */
int getnextlinelength(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
