// DELETE Nth NODE FROM LL

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Optimal one-pass function to remove N-th node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // If fast becomes NULL, we need to delete the head node
    if (!fast) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    ListNode* slow = head;

    // Move both pointers until fast reaches the last node
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the target node
    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a random test linked list: 10 -> 20 -> 30 -> 40 -> 50
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    cout << "Original list:\n";
    printList(head);

    int n = 2; // Remove the 2nd node from end (i.e., node with value 40)

    head = removeNthFromEnd(head, n);

    cout << "\nList after removing " << n << "th node from end:\n";
    printList(head);

    return 0;
}
