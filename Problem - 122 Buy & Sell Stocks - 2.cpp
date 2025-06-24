/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxprofit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) { 
            if (prices[i] > prices[i - 1]) { // if this happens then
                profit += prices[i] - prices[i - 1]; // update the profit (add it to their substracted value)
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;

    int arr[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> prices(arr, arr + size);

    int result = sol.maxprofit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

