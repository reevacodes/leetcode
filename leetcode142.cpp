// FIND THE STARTING NODE OF LOOP

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect the start of the cycle in a linked list
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // First phase: check if a cycle exists using Floyd’s cycle detection
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Second phase: reset one pointer to head
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Starting point of cycle
        }
    }

    return NULL;  // No cycle found
}

// Helper function to create a cycle for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* temp = head;
    ListNode* cycleStart = NULL;
    int index = 0;
    while (temp->next != NULL) {
        if (index == pos) {
            cycleStart = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = cycleStart;  // Create the cycle
}

int main() {
    // Create a linked list: 3 -> 2 -> 0 -> -4, with cycle starting at node with value 2
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    createCycle(head, 1);  // Create cycle at position 1 (value 2)

    ListNode* cycleStart = detectCycle(head);
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
