// ADD 2 NUMBERS

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to add two numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *t1 = l1;
  ListNode *t2 = l2;
  ListNode *dummyNode = new ListNode(-1);
  int carry = 0;
  ListNode *curr = dummyNode;

  while (t1 != NULL || t2 != NULL)
  {
    int sum = carry;
    if (t1)
      sum += t1->val;
    if (t2)
      sum += t2->val;

    ListNode *newNode = new ListNode(sum % 10);
    carry = sum / 10;
    curr->next = newNode;
    curr = curr->next;

    if (t1)
      t1 = t1->next;
    if (t2)
      t2 = t2->next;
  }

  if (carry == 1)
  {
    ListNode *extra = new ListNode(carry);
    curr->next = extra;
  }

  return dummyNode->next;
}

// Helper function to create a linked list from an array
ListNode *createList(int arr[], int n)
{
  ListNode *head = new ListNode(arr[0]);
  ListNode *curr = head;
  for (int i = 1; i < n; i++)
  {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }
  return head;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
  while (head != NULL)
  {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  // Example input: 342 + 465 = 807
  int arr1[] = {2, 4, 3};
  int arr2[] = {5, 6, 4};

  ListNode *l1 = createList(arr1, 3);
  ListNode *l2 = createList(arr2, 3);

  ListNode *result = addTwoNumbers(l1, l2);

  cout << "Result: ";
  printList(result);

  return 0;
}
