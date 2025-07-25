// CHECK IF LL IS A PALINDROME

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursive function to reverse a linked list
ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode* newHead = reverse(slow->next);
    ListNode* first = head;
    ListNode* second = newHead;

    // Compare both halves
    while (second != NULL) {
        if (first->val != second->val) {
            reverse(newHead);  // Restore the original list
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverse(newHead);  // Restore the original list
    return true;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> vals = {1, 2, 2, 1};
    ListNode* head = createList(vals);
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome.\n";
    } else {
        cout << "The linked list is not a palindrome.\n";
    }
    return 0;
}
