/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class Solution {
public:
    int maaxprofit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MIN;
        int sell = 0;

        for (int i = 0; i < n; i++) {
            buy = max(buy, -prices[i]); 
            sell = max(sell, buy + prices[i]);
        }
        return sell;
    }
};
int main() {
    Solution sol;

    int arr[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> prices(arr, arr + size);

    int result = sol.maaxprofit(prices);

    cout << "Maximum profit with 1 transaction: " << result << endl;

    return 0;
}


