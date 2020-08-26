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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root, bool flag = true) {
        vector<vector<int>> A;
        if(root == NULL) return A;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        vector<int> temp;
        TreeNode* tmp;
        while(!s1.empty() || !s2.empty()) {
            while(!s1.empty()) {
                tmp = s1.top();
                s1.pop();
                temp.push_back(tmp->val);
                if(tmp->left) s2.push(tmp->left);
                if(tmp->right) s2.push(tmp->right);
                
            }
            if(temp.size() != 0)
                A.push_back(temp);
            temp.clear();
            while(!s2.empty()) {
                tmp = s2.top();
                s2.pop();
                temp.push_back(tmp->val);
                
                if(tmp->right) s1.push(tmp->right);
                if(tmp->left) s1.push(tmp->left);
            }
            if(temp.size() != 0)
                A.push_back(temp);
            temp.clear();
        }
        return A;
    }
};

//Time Complexity O(H) where H is the height of the tree.