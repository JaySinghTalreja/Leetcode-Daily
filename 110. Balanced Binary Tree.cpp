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
    int heightDiff = 0;
    int check(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftHeight = check(root->left);
        int rightHeight = check(root->right);
        heightDiff = max(heightDiff, abs(leftHeight - rightHeight));
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        if(heightDiff<=1) {
            return true;
        }
        return false;
    }
};