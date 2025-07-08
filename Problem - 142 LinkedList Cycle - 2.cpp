#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Edge Cases
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next; // slow moves one step
            fast = fast->next->next; // fast moves two step
            if(slow == fast){
                slow = head; // if slow = fast then initialize slow as head

                // if not then move them one step
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // if slow = fast the slow = head
            }
        }
        return NULL; // no cycle detected
    }
};

// Function to create a linked list with a cycle
ListNode* createCyclicList() {
    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // cycle starts at node 3

    return head;
}

int main() {
    // Create cyclic list
    ListNode* head = createCyclicList();

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if(cycleStart != NULL) {
        cout << "Cycle detected. Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}

