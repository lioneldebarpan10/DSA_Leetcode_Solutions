/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/


#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    int maxprofit(vector<int>& prices) {
        // Max 2 transactions are allowed
        int n = prices.size();
        int firstbuy = INT_MIN;
        int firstsell = 0;
        int secondbuy = INT_MIN;
        int secondsell = 0;

        // first we have to buy a stock and before buying another
        // stock, we have to sell the previous one

        for (int i = 0; i < n; i++) {
            // Update the maximum profit for the first buy
            firstbuy = max(firstbuy, -prices[i]);

            // Update the maximum profit after first sell
            firstsell = max(firstsell, firstbuy + prices[i]);

            // Update the maximum profit after second buy
            secondbuy = max(secondbuy, firstsell - prices[i]);

            // Update the maximum profit after second sell
            secondsell = max(secondsell, secondbuy + prices[i]);
        }
        return secondsell;
    }
};
int main() {
    Solution sol;

    int arr[] = {3, 3, 5, 3, 8, 3, 1, 4};
    vector<int> prices(arr, arr + sizeof(arr)/sizeof(arr[0]));

    // Call the function and print the result
    int profit = sol.maxprofit(prices);

    cout << "Maximum profit with at most 2 transactions: " << profit << endl;

    return 0;
}

