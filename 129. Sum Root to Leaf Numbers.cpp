
//Time O(N) , N = Number of Nodes;
class Solution {
public:
    int sum = 0;
    void solve(TreeNode* root, int currentSum = 0) {
        if(root == NULL) {
            return;
        }
        currentSum = currentSum * 10;
        int newSum = currentSum + root->val;
        if(root->left == NULL && root->right == NULL) {
            sum += newSum;
            return;
        }
        solve(root->left, newSum);
        solve(root->right, newSum);
    }
    int sumNumbers(TreeNode* root) {
        solve(root);
        return sum;
    }
};