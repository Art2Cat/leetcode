#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void print(const struct ListNode *l) {
  const struct ListNode *tmp = l;
  while (tmp != NULL) {
    printf("%d, ", tmp->val);
    printf("%p\n", tmp);
    tmp = tmp->next;
  }
  printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  if (l1 == NULL && l2 == NULL) {
    return NULL;
  } else if (l1 == NULL) {
    return l2;
  } else if (l2 == NULL) {
    return l1;
  }
  struct ListNode *tmp = l1;
  int left_last = 0;
  while (tmp != NULL) {
    if (tmp->next == NULL) {
      left_last = tmp->val;
      tmp->next = l2;
      break;
    }
    tmp = tmp->next;
  }
  // after merge
  print(l1);

  // start sort;
  tmp = l1;
  struct ListNode *prev;
  while (tmp != NULL) {
    if (tmp->next != NULL && tmp->val > tmp->next->val) {
      if (prev != NULL) {
        prev->next = tmp->next;
      }
      struct ListNode *cur = tmp->next;
      struct ListNode *tmp1 = cur->next;
      tmp->next = tmp1;
      cur->next = tmp;
      prev = cur;
      continue;
    }
    prev = tmp;
    tmp = tmp->next;
  }
  print(l1);
  return l1;
}

int main() {
  struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
  l1->val = 1;
  l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l1->next->val = 5;
  l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l1->next->next->val = 6;
  l1->next->next->next = NULL;

  struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
  l2->val = 2;
  l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l2->next->val = 3;
  l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  l2->next->next->val = 4;
  l2->next->next->next = NULL;

  mergeTwoLists(l1, l2);

  return 0;
}
