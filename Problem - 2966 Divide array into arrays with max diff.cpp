/*You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return result; // return empty
            } else {
                vector<int> group;
                group.push_back(nums[i]);
                group.push_back(nums[i + 1]);
                group.push_back(nums[i + 2]);
                result.push_back(group);
            }
        }
        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements (multiple of 3): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Invalid input. Array size must be a multiple of 3." << endl;
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    vector<vector<int> > result = sol.divideArray(nums, k);

    if (result.empty()) {
        cout << "Not possible to divide the array with given k.\n";
    } else {
        cout << "The divided arrays are:\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "{ ";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << "}\n";
        }
    }

    return 0;
}

