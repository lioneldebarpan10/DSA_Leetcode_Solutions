/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search 
circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> res(n , -1);
        // for circular traversal
        for(int i = 2*n-1 ; i >= 0 ; i--){
            // While stack is not empty and 
            // top element is = current element, pop from stack.
            while(!stk.empty() && stk.top() <= nums[i % n]){
                stk.pop();
            }
            // if i < n and stack is not empty,
            // set res[i] to stk.top().
            if(i < n && !stk.empty()){
                res[i] = stk.top();
            }
            // push current element to the stack
            stk.push(nums[i % n]);
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next greater elements in circular array:\n";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

