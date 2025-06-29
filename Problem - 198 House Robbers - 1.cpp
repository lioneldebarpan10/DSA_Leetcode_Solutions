#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        int prev = nums[0]; // initializing that max sum ending at the element ago
        int prev2 = 0; // initializing that max sum ending at two elements ago

        for (int i = 1; i < n; i++) {
            int pick = nums[i]; // max sum if we pick current element
            if (i > 1) {
                pick += prev2; // add the max sum two elements ago
            }
            int not_pick = 0 + prev; // max sum after skipping current element
            int curr = max(pick, not_pick); // returns the max of them
            prev2 = prev; // update pointers
            prev = curr;
        }
        return prev; // returns the maximum sum
    }
};

int main() {
    Solution sol;

    // Dev C++ compatible array to vector conversion
    int arr[] = {2, 7, 9, 3, 1}; // Example house values
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + size); // Converting array to vector

    // Calling the rob function
    int maxMoney = sol.rob(nums);

    // Output the result
    cout << "Maximum amount that can be robbed: " << maxMoney << endl;

    return 0;
}

