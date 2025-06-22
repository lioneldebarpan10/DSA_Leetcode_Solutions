#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution{
	public:
		bool isValid(string s){
			stack<char> st; //Declare a Stack
			int i;
			for(i = 0 ; i < s.length() ; i++){
				char curr = s[i];
				if(!s.empty()){ // if stack is not empty then
					char tos = st.top(); // tos = top of the stack
					if(isPair(tos,curr)){
						st.pop(); // if combination is valid then pop it
						continue;
					}
				}
				st.push(curr); // if combination is not valid then push it 
			}
			return st.empty();
		}
		private:
			bool isPair(char tos , char curr){ // function of Valid Combination
				return 	(tos == '(' && curr == ')') ||
						(tos == '{' && curr == '}') ||
						(tos == '[' && curr == ']');
			}
};

int main() {
    Solution obj;
    string input;
    
    cout << "Enter a string containing brackets: ";
    cin >> input;

    if (obj.isValid(input)) {
        cout << "The string is valid.\n";
    } else {
        cout << "The string is NOT valid.\n";
    }

    return 0;
}
