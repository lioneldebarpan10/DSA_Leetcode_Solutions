/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution{
	public:
		// function to merge two sorted lists
		Node* mergeTwo(Node* head1 , Node* head2){
			Node* dummy = new Node(-1);
			Node* curr = dummy;
			// Traverse through the lists at a time
			while(head1 != NULL && head2 != NULL){
				// find out the smaller data from the list
				if(head1->data <= head2->data){
					curr->next = head1;
					head1 = head1->next;	
				}
				else{
					curr->next = head2;
					head2 = head2->next;
				}
				curr = curr->next;
			}
			// if any list is pending append it to merged list
			if(head1 != NULL){
				curr->next = head1;
			}
			else{
				curr->next = head2;
			}
			return dummy->next;
		}

		// function to merge two sorted lists using two pointer approach
		Node* mergerecurList(int i , int j , vector<Node*>&arr){
			// if single list is present
			if(i == j) return arr[i];
			
			int mid = i + (j - i) / 2;
			// sort the left half of array from i to mid
			Node* head1 = mergerecurList(i, mid, arr);
			// sort the right half of array from mid+1 to j
			Node* head2 = mergerecurList(mid + 1, j, arr);
			
			// Merge two sorted lists
			Node* head = mergeTwo(head1, head2);
			return head;	
		}
		
		Node* mergekSortedlists(vector<Node*>&arr){
			// if 0 list is present 
			if(arr.size() == 0) return NULL;
			return mergerecurList(0, arr.size() - 1, arr);		
		}
};

// function to print the linked list
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// helper function to create a linked list from vector
Node* createList(int arr[], int n) {
    if(n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Create input linked lists
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    Node* list1 = createList(arr1, 3);
    Node* list2 = createList(arr2, 3);
    Node* list3 = createList(arr3, 2);

    vector<Node*> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution sol;
    Node* mergedHead = sol.mergekSortedlists(lists);

    cout << "Merged Sorted Linked List: ";
    printList(mergedHead);

    return 0;
}

