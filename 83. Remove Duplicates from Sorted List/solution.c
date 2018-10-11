#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head) {
  if (head == NULL) {
    return NULL;
  }
  struct ListNode *tmp = head;
  while (tmp->next != NULL) {
    struct ListNode *next = tmp->next;
    if (tmp->val != next->val) {
      tmp = next;
      continue;
    }
    tmp->next = next->next;
  }

  return head;
}
