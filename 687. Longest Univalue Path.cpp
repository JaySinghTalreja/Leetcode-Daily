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
    int dfs(TreeNode *root, int currentVal, int &finalOutput) {
        if(root == NULL) {
            return 0;
        }
        if(root->val != currentVal) {
            dfs(root, root->val, finalOutput);
            return 0;
        }
        else {
            int left = dfs(root->left, currentVal, finalOutput);
            int right = dfs(root->right, currentVal, finalOutput);
            finalOutput = max(finalOutput, left + right);
            return 1 + max(left, right);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int finalOutput = 0;
        dfs(root, root->val, finalOutput);
        return finalOutput;
    }
};