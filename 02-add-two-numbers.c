#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *get_carry(struct ListNode *node, const int *carry) {
  if (node == NULL) {
    if (*carry) {
      struct ListNode *new_node =
          (struct ListNode *)malloc(sizeof(struct ListNode));
      new_node->next = NULL;
      new_node->val = *carry;
      return new_node;
    } else {
      return NULL;
    }
  }

  if (*carry) {
    node->val++;
  }
  return node;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  if (l1 == NULL && l2 == NULL) {
    return NULL;
  }

  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  int sum = ((l1 == NULL) ? 0 : l1->val) + ((l2 == NULL) ? 0 : l2->val);
  int carry = sum / 10;
  head->val = sum % 10;

  struct ListNode *carry_node =
      get_carry((l1 == NULL) ? NULL : l1->next, &carry);

  head->next = addTwoNumbers(carry_node, (l2 == NULL) ? NULL : l2->next);
  return head;
}
