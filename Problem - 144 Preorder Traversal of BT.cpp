/*Given the root of a binary tree, return the preorder traversal of its nodes' values.*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr; // array to store preorder node values
        preorder(root , arr); //call preorder function
        return arr; //return vector containing preorder values
    }
private:
    void preorder(TreeNode* root , vector<int>& arr){
        // if current node is null then return
        if(root == NULL) return;
        arr.push_back(root->val); // push the value of current node into array
        preorder(root->left , arr); //traverse left from root
        preorder(root->right , arr); // traverse right from root
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

