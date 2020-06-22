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
    bool check(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return check(p->left, q->right)  && check(p->right, q->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return check(root->left, root->right);
    }
};



//Stack -> DFS
//Stack can hold null! 
public boolean isSymmetric(TreeNode root) {
    if (root == null) return true;
    Stack<TreeNode> stack = new Stack<>();
    stack.push(root.left);
    stack.push(root.right);
    while (!stack.empty()) {
        TreeNode n1 = stack.pop(), n2 = stack.pop();
        if (n1 == null && n2 == null) continue;
        if (n1 == null || n2 == null || n1.val != n2.val) return false;
        stack.push(n1.left);
        stack.push(n2.right);
        stack.push(n1.right);
        stack.push(n2.left);
    }
    return true;
}


//BFS Iterative
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};