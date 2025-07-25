// DETECT A LOOP IN A LL

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect if a cycle exists
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Helper to create a cycle for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* tail = head;
    ListNode* cycleStart = nullptr;
    int idx = 0;

    while (tail->next != NULL) {
        if (idx == pos) cycleStart = tail;
        tail = tail->next;
        idx++;
    }
    tail->next = cycleStart;
}

int main() {
    // Create list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    createCycle(head, 1); // Make a cycle at node with value 2 (position 1)

    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list.\n";
    } else {
        cout << "No cycle in the linked list.\n";
    }

    return 0;
}
