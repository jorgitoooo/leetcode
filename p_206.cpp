/* ---------------
 * Jorge L. Garcia
 * //2019
 * ---------------
 * Reverse Linked
 * List
 */

#include <iostream>
#include "listnode.h"

using namespace std;

ListNode* reverseList(ListNode* head)
{
  if(!head) return NULL;
        
  ListNode *reverser = head, *next_node = head->next;
        
  reverser->next = NULL;
  while(next_node){
    ListNode *tmp = next_node->next;
    next_node->next = reverser;
    reverser = next_node;
    next_node = tmp;
  }
  return reverser;
}

void print(ListNode *r)
{
	ListNode *node = r;
	while(node) {
		printf("%d ", node->val);
		node = node->next;
	}
}

int main(int argc, char **argv)
{
	ListNode *r  = new ListNode(0);
	ListNode *n1 = new ListNode(1);
	r->next = n1;
	ListNode *n2 = new ListNode(2);
	n1->next = n2;
	ListNode *n3 = new ListNode(3);
	n2->next = n3;
	ListNode *n4 = new ListNode(4);
	n3->next = n4;

	printf("Linked list: ");
	print(r);

	ListNode *rr = reverseList(r);

	printf("\nReversed linked list: ");
	print(rr);
	printf("\n\n");

	return 0;
}
