#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int size;
  int min;
} MinStack;

/** initialize your data structure here. */
MinStack *minStackCreate(int maxSize) {
  MinStack *s = (MinStack *)malloc(sizeof(MinStack));
  s->arr = (int *)malloc(sizeof(int) * maxSize);
  s->size = 0;
  s->min = 0;
  return s;
}

void minStackPush(MinStack *obj, int x) {
  if (obj->size == 0) {
    obj->arr[0] = x;
    obj->min = x;
    obj->size++;
  } else {
    obj->arr[obj->size] = x;
    obj->size++;
    if (obj->min > x) {
      obj->min = x;
    }
  }
}

void minStackPop(MinStack *obj) {
  obj->min = obj->arr[0];
  obj->arr[obj->size - 1] = obj->arr[obj->size + 1];
  obj->size--;
  for (int i = 0; i < obj->size; i++) {
    if (obj->min > obj->arr[i]) {
      obj->min = obj->arr[i];
    }
  }
}

int minStackTop(MinStack *obj) { return obj->arr[obj->size - 1]; }

int minStackGetMin(MinStack *obj) { return obj->min; }

void minStackFree(MinStack *obj) { free(obj); }
/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

int main() {
  MinStack *min_stack = minStackCreate(5);
  minStackPush(min_stack, -1);
  printf("%d\n", minStackGetMin(min_stack));
  minStackPop(min_stack);
  printf("%d\n", minStackTop(min_stack));
  printf("%d\n", minStackGetMin(min_stack));
  return 0;
}
