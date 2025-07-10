/*Given the root of a binary tree, return the postorder traversal of its nodes' values.*/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr; // to store the value of postorder traversal
        postorder(root , arr); // call postorder function
        return arr;
    }

private:
    void postorder(TreeNode* root , vector<int>& arr) {
        // if node is null then return it
        if(root == NULL) return;
        postorder(root->left , arr); // traverse left at first
        postorder(root->right , arr); // traverse right at first
        arr.push_back(root->val); // then root
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

