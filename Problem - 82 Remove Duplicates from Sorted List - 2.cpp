/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0); // create dummy node before head to handle edge Cases
        dummy->next = head;
        ListNode* prev = dummy; // tracks the last confirmed non-duplicate Node
        ListNode* curr = head;  // moves through the list to find duplicates

        while(curr != NULL){
            // if current node and next node have same value, skip all nodes with that value
            if(curr->next && curr->val == curr->next->val){
                while(curr->next && curr->val == curr->next->val){
                    curr = curr->next; // move curr to last duplicate
                }
                prev->next = curr->next; // skip all duplicates
            }
            else{
                prev = prev->next; // no duplicate, move prev
            }
            curr = curr->next; // always move curr
        }
        return dummy->next; 
    }
};

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

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test list: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head); 

    cout << "After Removing All Duplicates: ";
    printList(head);

    return 0;
}
