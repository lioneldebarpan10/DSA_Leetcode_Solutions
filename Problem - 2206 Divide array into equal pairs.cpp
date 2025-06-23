/*You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int size;
    cout << "Enter the size of the array (even number): ";
    cin >> size;

    if (size % 2 != 0) {
        cout << "Array size must be even." << endl;
        return 1;
    }

    vector<int> nums(size);
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    bool result = sol.divideArray(nums);
    if (result) {
        cout << "The array can be divided into equal pairs." << endl;
    } else {
        cout << "The array cannot be divided into equal pairs." << endl;
    }

    return 0;
}

