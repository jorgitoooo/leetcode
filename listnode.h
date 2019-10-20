#ifndef __LISTNODE__
#define __LISTNODE__

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
} ListNode;

#endif
