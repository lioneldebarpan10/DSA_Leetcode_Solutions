/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> stk; // stack for tracking next greater element

        for(int num : nums2){
            // if stack is not empty and num is greater than tos then
            // for example - nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]
            // stack is empty push 1, then 3 > 1
            // pop 1, and set map[1] = 3 and push 3
            while(!stk.empty() && num > stk.top()){
                mpp[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        // for remaining elements, for example
        // 4 and 2 assigned as -1
        while(!stk.empty()){
            mpp[stk.top()] = -1;
            stk.pop();
        }

        // push num into the ans array
        vector<int> ans;
        for(int num : nums1){
            ans.push_back(mpp[num]);      
        }  
        return ans; 
    }
};

int main() {
    int n1, n2;
    cout << "Enter size of nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter " << n1 << " elements of nums1:\n";
    for(int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of nums2: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter " << n2 << " elements of nums2:\n";
    for(int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements:\n";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

