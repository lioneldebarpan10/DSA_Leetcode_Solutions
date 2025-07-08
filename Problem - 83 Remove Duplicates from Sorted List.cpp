/*Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
 Return the linked list sorted as well.*/
#include <iostream>
using namespace std;

// Definition of singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head; // init temp as head
        if(head == NULL) return NULL;
        while(head != NULL && head->next != NULL){
            // if duplicates are found then
            // change the links
            if(head->val == head->next->val){ 
                head->next = head->next->next;
            }
            // else move head pointers
            else{
                head = head->next;
            }
        }
        return temp;
    }
};

// Utility function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if(n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create input list: 1 -> 1 -> 2 -> 3 -> 3
    int arr[] = {1, 1, 2, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head); // remove duplicates

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}

