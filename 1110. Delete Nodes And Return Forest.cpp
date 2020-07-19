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
    set<int> varSet;
    vector<TreeNode *> nodes;
    TreeNode* helper(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        root->left = helper(root->left);
        root->right = helper(root->right);
        auto it = varSet.find(root->val);
        if(it != varSet.end()) {
            if(root->left)
                nodes.push_back(root->left);
            if(root->right)
                nodes.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto A : to_delete) varSet.insert(A);
        auto it = varSet.find(root->val);
        if(it == varSet.end()) nodes.push_back(root);
        helper(root);
        return nodes;
    }
};
/*
Complexity
Time O(N)
Space O(H + N), where H is the height of tree.
*/