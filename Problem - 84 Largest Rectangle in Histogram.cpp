/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangle(vector<int> heights) {
        int n = heights.size();
        stack<int> stk;
        int maxarea = 0;
		// Traverse all bars including one extra pass for cleanup
        for (int i = 0; i <= n; i++) {
            // While current height is smaller than top of stack
            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
                int height = heights[stk.top()];
                stk.pop();
				// Calculate width for current height
                int width;
                if (stk.empty()) {
                    width = i;
                } else {
                    width = i - stk.top() - 1;
                }
				// calculate Maxarea
                maxarea = max(maxarea, width * height);
            }
            stk.push(i); // push current index
        }

        return maxarea;
    }
};

int main() {
    Solution sol;
    vector<int> heights;
    int n, h;

    cout << "Enter number of bars: ";
    cin >> n;

    cout << "Enter the heights of the bars:\n";
    for (int i = 0; i < n; i++) {
        cin >> h;
        heights.push_back(h);
    }

    int result = sol.largestRectangle(heights);
    cout << "Largest rectangle area: " << result << endl;

    return 0;
}

