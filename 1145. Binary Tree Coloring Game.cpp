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
    int left=0, right=0;
    int count(TreeNode *root, int x) {
        if(root == NULL) {
            return 0;
        }
        int leftCount = count(root->left, x);
        int rightCount = count(root->right, x);
        if(root->val == x) {
            left = leftCount;
            right = rightCount;
        }
        return leftCount + rightCount + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);
        return max(n-left-right-1, max(left, right)) > n/2;
    }
};


//Time Complexity - O(N), Space(O(N)) // Recursion Stack