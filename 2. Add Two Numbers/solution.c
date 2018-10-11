#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
  result->next = NULL;
  struct ListNode *next;
  struct ListNode *tmp = result;
  int a = 0;
  while (l1 && l2) {
    int l1_val = (l1 ? l1->val : 0);
    int l2_val = (l2 ? l2->val : 0);
    int tmp_val = l1_val + l2_val + a;
    a = tmp_val / 10;

    next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    next->val = tmp_val % 10;
    tmp->next = next;
    tmp = next;
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
  }
  if (a > 0) {
    next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    next->val = a;
    tmp->next = next;
  }
  return result->next;
}

int main() { return 0; }
