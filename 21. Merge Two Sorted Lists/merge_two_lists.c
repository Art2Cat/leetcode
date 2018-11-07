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
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;

  struct ListNode result;
  struct ListNode *curr = &result;
  struct ListNode *l_tmp = l1;
  struct ListNode *r_tmp = l2;
  while (l_tmp && r_tmp) {
    curr->next = (l_tmp->val < r_tmp->val) ? l_tmp : r_tmp;
    if (l_tmp->val < r_tmp->val) {
      l_tmp = l_tmp->next;
    } else {
      r_tmp = r_tmp->next;
    }
    curr = curr->next;
  }
  curr->next = l_tmp ? l_tmp : r_tmp;
  return result.next;
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

  struct ListNode *result = mergeTwoLists(l1, l2);
  print(result);
  return 0;
}
