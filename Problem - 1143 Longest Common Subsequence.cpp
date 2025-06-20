/*Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    int i, j;
    //Creating a dp matrix of size of (m+1)*(n+1)
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

	//building dp[m+1][n+1] in bottom-up fashion
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
        	// if element of string matched then
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            // if element of string doesn't matched
			else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int length = LCS(s1, s2);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}

