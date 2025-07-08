/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next; //move once at a time
            fast = fast->next->next; // move twice at a time
            if(slow == fast){
                return true; // if both meets then true
            }
        }
        return false; // else false
    }
};

// Function to create a linked list with a cycle for testing
ListNode* createCyclicList() {
    // Create nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // creates a cycle (4 -> 2)

    return head;
}

// Function to create a non-cyclic list
ListNode* createNonCyclicList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    return head;
}

int main() {
    Solution sol;

    // Test Case 1: List with a cycle
    ListNode* cycleList = createCyclicList();
    if(sol.hasCycle(cycleList))
        cout << "Cycle detected in cycleList." << endl;
    else
        cout << "No cycle in cycleList." << endl;

    // Test Case 2: List without a cycle
    ListNode* noCycleList = createNonCyclicList();
    if(sol.hasCycle(noCycleList))
        cout << "Cycle detected in noCycleList." << endl;
    else
        cout << "No cycle in noCycleList." << endl;

    return 0;
}

