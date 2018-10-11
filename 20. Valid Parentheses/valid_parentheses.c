#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s) {
  int len = strlen(s);
  if (0 == len) {
    return true;
  }
  if (len % 2 != 0) {
    return false;
  }
  char list[128] = {0};
  int a = '(';
  int b = '[';
  int c = '{';
  list[a] = ')';
  list[b] = ']';
  list[c] = '}';

  int size = 0;
  int *stack = (int *)malloc(sizeof(int) * len);

  stack[size++] = *s++;
  while (*s) {
    if (*s == '(' || *s == '[' || *s == '{') {
      stack[size++] = *s;
    } else if (*s == ')' || *s == ']' || *s == '}') {
      if (list[stack[size - 1]] == *s) {
        --size;
      }
    } else {
      continue;
    }
    ++s;
  }
  free(stack);
  return !size;
}

int main() {
  char *source = "()";
  char *source1 = "";
  char *source2 = "{[]}";
  char *source3 = "([)]";
  char *source4 = "()[]{}";
  char *source5 = "{[()]}";
  char *source6 = "{[](){{[]}}}";
  printf("%d\n", isValid(source));
  printf("%d\n", isValid(source1));
  printf("%d\n", isValid(source2));
  printf("%d\n", isValid(source3));
  printf("%d\n", isValid(source4));
  printf("%d\n", isValid(source5));
  printf("%d\n", isValid(source6));
  return 0;
}
