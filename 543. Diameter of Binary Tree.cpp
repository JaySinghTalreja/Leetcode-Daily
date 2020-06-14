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
private:
    int height;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        this->height=1;
        dox(root);
        return this->height - 1;
    }
    int dox(TreeNode* root){
        if(root  == NULL){
            return 0;
        }
        int left = dox(root->left);
        int right = dox(root->right);
        this->height = max(height, left+right+1);
        return 1+max(left,right);
    }
};