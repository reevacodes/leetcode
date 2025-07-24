//  REVERSE LINKED LIST

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Recursive approach to reverse the linked list
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

/*
// Iterative approach (uncomment to use)
ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
*/

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return NULL;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (int i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
