/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        // Edge Cases
        if(curr == NULL || k == 1) return head;

        // Now Count the no of nodes
        int count = 0;
        while(curr != NULL){
            count++;
            curr = curr->next;
        } 

        // update curr and next while count is greater than equal to k
        while(count >= k){
            curr = prev->next;
            ListNode* next = curr->next;

            for(int i = 1 ; i < k ; i++){
                // 1st iteration -> curr = 1 , next = 2 , next->next = 3
                curr->next = next->next;    // next of 1 is 3 , 2 (next) is disconnected [1 -> 3]
                next->next = prev->next;    // next of 2 is 1 , now [2 -> 1]
                prev->next = next;          // prev points to 2 [prev -> 2]
                next = curr->next;          // curr = 1 , curr->next = 3 ; next = 3
                // updated list = prev-> 2-> 1-> 3-> NULL
            }

            prev = curr;    
            count = count - k; // decrease the count up to k
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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseKGroup(head, k); 

    cout << "Reversed in Groups of " << k << ": ";
    printList(head);

    return 0;
}

