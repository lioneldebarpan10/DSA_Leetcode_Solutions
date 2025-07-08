#include <iostream>
using namespace std;

// Definition of singly-linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

class Solution{
	public:
		ListNode* mergeTwolists(ListNode* list1 , ListNode* list2){
			// if 1st list is null then return 2nd list
			if(list1 == NULL){
				return list2;
			}
			// if 2nd list is null then return 1st list
			if(list2 == NULL){
				return list1;
			}
			// if value of list1 is less than or equal to list2
			// kept it and set it's next pointer recursively
			if(list1->data <= list2->data){
				list1->next = mergeTwolists(list1->next , list2);
				return list1;
			}
			// if value of list2 is less than or equal to list1
			// kept it and set it's next pointer recursively
			else{
				list2->next = mergeTwolists(list1 , list2->next);
				return list2;
			}
		}
};

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    int arr1[] = {1, 3, 5};
    ListNode* list1 = createList(arr1, 3);

    // Create second sorted list: 2 -> 4 -> 6
    int arr2[] = {2, 4, 6};
    ListNode* list2 = createList(arr2, 3);

    // Merge the two lists
    Solution obj;
    ListNode* mergedList = obj.mergeTwolists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

