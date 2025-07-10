/*Given the root of a binary tree, return the inorder traversal of its nodes' values.*/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr; // arr to store the values of inorder traversal
        inorder(root , arr); // call inorder function
        return arr;
    }

private:
    // Function to perform inorder traversal
    // of the tree and store values in 'arr'
    void inorder(TreeNode* root , vector<int>& arr) {
        // If the current node is NULL then return
        if(root == NULL) return;
        inorder(root->left , arr); // traverse left at first
        arr.push_back(root->val);  // then root
        inorder(root->right , arr); // then traverse right at last
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

