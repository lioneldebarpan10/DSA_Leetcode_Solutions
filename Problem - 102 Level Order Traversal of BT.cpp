/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/
#include <iostream>
#include <vector>
#include <queue> 
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        // Vector to store the result of BFS
        vector<vector<int> > ans;
        if(root == NULL) return ans; // Edge Case;
        queue<TreeNode*> que; // declare queue
        que.push(root); // push root onto the queue
        while(!que.empty()) {
            int n = que.size(); // size of the queue
            vector<int> level;
            for(int i = 0 ; i < n ; i++) {
                TreeNode* Node = que.front();
                que.pop(); // pop from the front of the queue
                if(Node->left != NULL) {
                    que.push(Node->left); // Push Left Node in the Queue
                }
                if(Node->right != NULL) {
                    que.push(Node->right); // Push Right Node in the queue
                }
                level.push_back(Node->val); // value of node pushed onto level array
            }
            ans.push_back(level);
        }
        return ans; // final outcome of BFS traversal
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int> > result = sol.levelOrder(root);

    cout << "Level Order Traversal: " << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

