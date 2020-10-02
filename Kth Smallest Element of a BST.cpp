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


//Using Priority Queue
class Solution {
public:
    void solve(TreeNode* root, priority_queue <int, vector<int>, greater<int>> &elements) {
        if(root == NULL) {
            return;
        }
        solve(root->left, elements);
        solve(root->right, elements);
        elements.push(root->val);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue <int, vector<int>, greater<int>> elements;
        solve(root, elements);
        int min = INT_MAX;
        for(int i=0;i<k-1;i++) {
            elements.pop();
        }
        return elements.top();
    }
};


//Using InOrder Traversal    (Important Techniqye)





class Solution {
public:
    void solve(TreeNode* root, int &K, int &minElement) {
        if(root == NULL) {
            return;
        }
        solve(root->left, K, minElement);
        if(K != 0) minElement = root->val,K--;
        solve(root->right, K, minElement);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        //priority_queue <int, vector<int>, greater<int>> elements;
        int minElement = INT_MAX;
        solve(root, k, minElement);
        return minElement;
    }
};