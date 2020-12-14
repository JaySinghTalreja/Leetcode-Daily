/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode* root, vector<vector<int>> &result) {
        if(root == NULL) return;
        queue<TreeNode*> varQueue;
        varQueue.push(root);
        while(!varQueue.empty()) {
            int size = varQueue.size();
            vector<int> tempOutput;
            while(size--) {
                TreeNode* temp = varQueue.front();
                varQueue.pop();
                tempOutput.push_back(temp->val);
                if(temp->left) varQueue.push(temp->left);
                if(temp->right) varQueue.push(temp->right);
            }
            result.push_back(tempOutput);
            tempOutput.clear();
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        solve(root, result);
        return result;
    }
};
