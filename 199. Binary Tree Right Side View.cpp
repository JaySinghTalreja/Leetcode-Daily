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
//Time Complexity O(N)
class Solution {
public:
    map<int, int> varMap;
    void solve(TreeNode* root, int level = 0) {
        if(root == NULL) {
            return;
        }
        varMap[level] = root->val;
        solve(root->left, level + 1);
        solve(root->right, level + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root);
        vector<int> ans;
        for(auto Value: varMap) {
            ans.push_back(Value.second);
        }
        return ans;
    }
};