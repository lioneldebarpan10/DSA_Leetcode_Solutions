#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to calculate max area in histogram
    int getMaxArea(const vector<int> &arr) {
        stack<int> stk;
        int n = arr.size();
        int maxarea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : arr[i];

            while (!stk.empty() && arr[stk.top()] >= currHeight) {
                int height = arr[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxarea = max(maxarea, height * width);
            }

            stk.push(i);
        }

        return maxarea;
    }

    // Function to find maximal rectangle in binary matrix
    int MaxRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    arr[j]++;
                } else {
                    arr[j] = 0;
                }
            }
            ans = max(ans, getMaxArea(arr));
        }

        return ans;
    }
};

// Main function for testing
int main() {
    Solution obj;

    // Declare 2D char matrix using traditional style
    char temp[4][5] = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    vector<vector<char> > matrix(4, vector<char>(5));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = temp[i][j];
        }
    }

    int result = obj.MaxRectangle(matrix);
    cout << "Maximal Rectangle Area = " << result << endl;

    return 0;
}


