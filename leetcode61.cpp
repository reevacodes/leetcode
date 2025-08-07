// ROTAT THE LL K TIMES

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

// Helper function to find the k-th node
ListNode *findKthNode(ListNode *head, int cnt)
{
  ListNode *temp = head;
  cnt -= 1;
  while (cnt--)
  {
    temp = temp->next;
  }
  return temp;
}

// Function to rotate the list
ListNode *rotateRight(ListNode *head, int k)
{
  if (!head || k == 0)
    return head;

  // Find length and tail
  ListNode *tail = head;
  int len = 1;
  while (tail->next)
  {
    len++;
    tail = tail->next;
  }

  // Adjust k
  k = k % len;
  if (k == 0)
    return head;

  // Make circular
  tail->next = head;

  // Find new last node
  ListNode *newLastNode = findKthNode(head, len - k);
  head = newLastNode->next;
  newLastNode->next = nullptr;

  return head;
}

// Function to create a linked list from an array
ListNode *createList(const int arr[], int n)
{
  if (n == 0)
    return nullptr;
  ListNode *head = new ListNode(arr[0]);
  ListNode *curr = head;
  for (int i = 1; i < n; ++i)
  {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }
  return head;
}

// Function to print the linked list
void printList(ListNode *head)
{
  while (head)
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
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 2;

  ListNode *head = createList(arr, n);

  cout << "Original List: ";
  printList(head);

  head = rotateRight(head, k);

  cout << "Rotated List by " << k << ": ";
  printList(head);

  return 0;
}
