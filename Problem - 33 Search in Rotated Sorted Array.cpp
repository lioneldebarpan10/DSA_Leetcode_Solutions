/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int search(vector<int>& nums, int target){
            int n = nums.size();
            int low = 0 , high = n - 1;

            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[mid] == target){
                    return mid;
                }
                // Left part is sorted
                else if(nums[low] <= nums[mid]){
                    // Target lies in the left half
                    if(nums[low] <= target && target < nums[mid]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                // Right part is sorted
                else{
                    // Target lies in the right half
                    if(nums[high] >= target && target > nums[mid]){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
            }
            return -1; // Target not found
        }
};

int main() {
    Solution sol;

    // Dev C++ compatible array to vector conversion
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + size);

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    int index = sol.search(nums, target);

    if(index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}

