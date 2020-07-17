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
    /*int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return 1+left+right;
    }
    */
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        auto left = root, right = root;
        int leftHeight = 0, rightHeight =0;
        while(left != NULL) {
            leftHeight++;
            left = left->left;
        }
        while(right != NULL) {
            rightHeight++;
            right = right->right;
        }
        if(leftHeight == rightHeight) return (1<<leftHeight)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};