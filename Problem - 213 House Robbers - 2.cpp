#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate max money between house x to y (inclusive)
    int maxval(int x, int y, vector<int> &nums) {
        int n = nums.size();

        // Base case: if there's only one house in this range
        if (x == y) return nums[x];

        // For first house, taking is only option
        int prev2 = nums[x];
        // For second house, we can either take from 1st or 2nd
        int prev1 = max(nums[x], nums[x + 1]);

        for (int i = x + 2; i <= y; i++) {
            int pick = nums[i] + prev2;
            int not_pick = prev1;

            int curr = max(pick, not_pick);
            // update states
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    // Main function to return max amount that can be robbed
    int rob(vector<int> &nums) {
        int n = nums.size();

        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int ans = 0;
        // Skipping last house 
        ans = max(ans, maxval(0, n - 2, nums));
        // Skipping First house 
        ans = max(ans, maxval(1, n - 1, nums));

        return ans;  
    }
};

int main() {
    Solution sol;

    int arr[] = {2, 3, 7 , 8 , 9 , 2}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + size); 

    int maxMoney = sol.rob(nums);

    cout << "Maximum amount that can be robbed: " << maxMoney << endl;

    return 0;
}

