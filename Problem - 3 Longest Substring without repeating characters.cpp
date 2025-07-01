#include <iostream>
#include <unordered_set>
#include <climits> // for INT_MIN
#include <string>  // for string operations
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // Base Cases
        if(n == 0) return 0;
        if(n == 1) return 1;

        unordered_set<int> st; // declare set to store unique elements
        int maxans = INT_MIN;
        int left = 0; // pointing left & right at same index
        for(int right = 0 ; right < n ; right++){ // traversal of string using right pointer
            if(st.find(s[right]) != st.end()){ // if duplicates are found

                while(left < right && st.find(s[right]) != st.end()){
                    st.erase(s[left]); // if duplicates are found erase from left and update it
                    left++; // in this way we get unique substring of elements
                }
            } 
            st.insert(s[right]); // insert element in the set
            maxans = max(maxans , right - left + 1); // update length to its maximum
        }
        return maxans; // return max length
    }
};

int main() {
    Solution sol;
    
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Call the function and print the result
    int result = sol.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}

