#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
  if (!headA || !headB)
    return NULL;

  ListNode *t1 = headA;
  ListNode *t2 = headB;

  while (t1 != t2)
  {
    t1 = (t1 == NULL) ? headB : t1->next;
    t2 = (t2 == NULL) ? headA : t2->next;
  }

  return t1; // Either intersection node or NULL
}

int main()
{
  // Create common part
  ListNode *common = new ListNode(8);
  common->next = new ListNode(10);

  // First linked list: 3 -> 7 -> 8 -> 10
  ListNode *headA = new ListNode(3);
  headA->next = new ListNode(7);
  headA->next->next = common;

  // Second linked list: 99 -> 1 -> 8 -> 10
  ListNode *headB = new ListNode(99);
  headB->next = new ListNode(1);
  headB->next->next = common;

  ListNode *intersection = getIntersectionNode(headA, headB);

  if (intersection)
  {
    cout << "Intersection at node with value: " << intersection->val << endl;
  }
  else
  {
    cout << "No intersection found." << endl;
  }

  return 0;
}
