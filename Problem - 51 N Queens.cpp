#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool isSafe(int row, int col, vector<string>& boards, int n) {
    	int i,j;
    	//Check the upper column 
        for (int i = 0; i < row; i++) {
            if (boards[i][col] == 'Q') return false;
        }
		//Check the upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (boards[i][j] == 'Q') return false;
        }
		//Check the upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (boards[i][j] == 'Q') return false;
        }
        return true;
    }

    void placeQueens(int row, vector<string>& boards, vector<vector<string> >& ans, int n) {
    	// base case: If all queens are placed
        // then return 
        int col;
        if (row == n) {
            ans.push_back(boards);
            return;
        }
		//Consider row and try to place queens in columns
        for (col = 0; col < n; col++) {
            if (isSafe(row, col, boards, n)) {
                boards[row][col] = 'Q'; // Place the Queens
                placeQueens(row + 1, boards, ans, n); // Recurse the Function
                boards[row][col] = '.'; // Backtrack
            }
        }
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> boards(n, string(n, '.')); // n x n matrix filled with '.'
        placeQueens(0, boards, ans, n);
        return ans;
    }
};

int main() {
    int n , k , i;
    cout << "Enter the value of N: ";
    cin >> n;

    Solution sol;
    vector<vector<string> > results = sol.solveNQueens(n);

    cout << "\nTotal solutions: " << results.size() << "\n";

    for (k = 0; k < results.size(); ++k) {
        cout << "Solution " << k + 1 << ":\n";
        for ( i = 0; i < results[k].size(); ++i) {
    		cout << results[k][i] << "\n";
		}
        cout << "\n";
    }

    return 0;
}

