/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> nums;
		int i,j;
        // Push all elements in nums1
        for (i = 0; i < m; i++) {
            nums.push_back(nums1[i]);
        }

        // Push all elements in nums2
        for (j = 0; j < n; j++) {
            nums.push_back(nums2[j]);
        }

        // Sort the combined array
        sort(nums.begin(), nums.end());

        int k = nums.size();

        // If size is odd
        if (k % 2 == 1) {
            return static_cast<double>(nums[k / 2]);
        }
        else { // If size is even
            int k1 = nums[k / 2 - 1];
            int k2 = nums[k / 2];
            return (static_cast<double>(k1) + static_cast<double>(k2)) / 2.0;
        }
    }
};

int main() {
    Solution sol;
    int m, n, temp;

    vector<int> nums1, nums2;

    cout << "Enter size of first sorted array: ";
    cin >> m;
    cout << "Enter " << m << " elements of first sorted array:\n";
    for (int i = 0; i < m; i++) {
        cin >> temp;
        nums1.push_back(temp);
    }

    cout << "Enter size of second sorted array: ";
    cin >> n;
    cout << "Enter " << n << " elements of second sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums2.push_back(temp);
    }

    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median of the two sorted arrays is: " << median << endl;

    return 0;
}

