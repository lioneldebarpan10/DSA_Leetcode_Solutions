/*There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Skip duplicates
            if (nums[mid] == nums[low]) {
                low++;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};
int main() {
    Solution sol;

    // Array initialization (rotated sorted array with duplicates)
    int arr[] = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + size);

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    bool found = sol.search(nums, target);

    if (found) {
        cout << "Target is present in the array." << endl;
    } else {
        cout << "Target is NOT present in the array." << endl;
    }

    return 0;
}

