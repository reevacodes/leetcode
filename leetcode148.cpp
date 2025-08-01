#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle of the linked list
ListNode *findMiddle(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Function to merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  ListNode *dummyNode = new ListNode(-1);
  ListNode *temp = dummyNode;

  while (list1 && list2)
  {
    if (list1->val < list2->val)
    {
      temp->next = list1;
      list1 = list1->next;
    }
    else
    {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }

  if (list1)
    temp->next = list1;
  else
    temp->next = list2;

  return dummyNode->next;
}

// Main merge sort function
ListNode *sortList(ListNode *head)
{
  if (!head || !head->next)
    return head;

  ListNode *middle = findMiddle(head);
  ListNode *right = middle->next;
  middle->next = nullptr;

  ListNode *left = sortList(head);
  right = sortList(right);

  return mergeTwoLists(left, right);
}

// Helper function to print the list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

// Sample usage
int main()
{
  // Creating the list: 4 -> 2 -> 1 -> 3
  ListNode *head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  // Sorting the list
  head = sortList(head);

  // Printing the sorted list
  printList(head);

  return 0;
}
