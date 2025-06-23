/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

#include <iostream>
using namespace std;
class Solution{
	public:
		int climbStairs(int n){
			
			if(n <= 3) return n;
			int prev1 = 3;
			int prev2 = 2;
			int curr = 0;
			int i;
			for(i = 3 ; i < n ; i++){
				curr = prev1 + prev2;
				prev2 = prev1;
				prev1 = curr;
			}
			return curr;
		}
};
int main() {
    Solution sol;
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    int ways = sol.climbStairs(n);
    cout << "Number of distinct ways to climb to the top: " << ways << endl;

    return 0;
}
