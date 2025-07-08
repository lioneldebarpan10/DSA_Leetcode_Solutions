#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class with deleteMiddle function
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp; // Free memory of deleted node
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example input: 1 -> 2 -> 3 -> 4 -> 5
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}

