/* ---------------
 * Jorge L. Garcia
 * //2019
 * ---------------
 * Intersection of
 * Two Linked
 * Lists
 */

#include <iostream>
#include <set>

#include "listnode.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
  if(!headA || !headB) return NULL;
    
  int count_a = 1, count_b = 1;
  ListNode *n_a = headA, *n_b = headB;
  while(n_a->next){
    count_a++;
    n_a = n_a->next;
  }
  while(n_b->next){
    count_b++;
    n_b = n_b->next;
  }
  if(n_a == n_b){
    n_a = headA;
    n_b = headB;
          
    set<ListNode*> n_set;
    if(count_b > count_a){
      ListNode *tmp = n_a;
      n_a = n_b;
      n_b = tmp;
    }
    while(n_b){
      n_set.insert(n_b);
      n_b = n_b->next;
    }
    while(n_a){
      if(n_set.find(n_a) != n_set.end()) return n_a;
      n_a = n_a->next;
    }
  }
  return NULL;
}

int main(int argc, char **argv)
{
	// headA
	ListNode *ra = new ListNode(0);
	ListNode *n1 = new ListNode(1);
	ra->next = n1;
	ListNode *n2 = new ListNode(2);
	n1->next = n2;
	ListNode *n3 = new ListNode(3);
	n2->next = n3;
	ListNode *n4 = new ListNode(4);
	n3->next = n4;
	ListNode *n5 = new ListNode(5);
	n4->next = n5;

	// headB
	ListNode *rb = new ListNode(0);
	ListNode *n6 = new ListNode(6);
	rb->next = n6;
	ListNode *n7 = new ListNode(7);
	n6->next = n7;
	ListNode *n8 = new ListNode(8);
	n7->next = n8;
	
	// Intersection
	n8->next = n3;

	// Intersection value should be 3
	ListNode *n_intersect	= getIntersectionNode(ra,rb);

	if(n_intersect)
		printf("val %d\n", n_intersect->val);

	return 0;
}
