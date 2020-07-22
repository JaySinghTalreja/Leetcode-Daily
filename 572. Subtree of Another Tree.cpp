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
//Pre Order
class Solution {
public:
    bool checkTree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t==NULL) return true;
        if( s== NULL || t == NULL) return false;
        if(s->val != t->val) return false;
        return checkTree(s->left, t->left) && checkTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL) return false;
        if(checkTree(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};


//Alternative BFS
public boolean isSubtree(TreeNode s, TreeNode t) {
    Queue<TreeNode> nodes = new ArrayDeque<>();
    nodes.offer(s);
    while (!nodes.isEmpty()) {
        TreeNode node = nodes.poll();
        if (isSameTree(node, t)) {
            return true;
        }
        if (node.left != null) {
            nodes.offer(node.left);
        }
        if (node.right != null) {
            nodes.offer(node.right);
        }
    }
    return false;
}


public boolean isSameTree(TreeNode s, TreeNode t) {
    if (s == null && t == null) {
        return true;
    }
    if (s == null || t == null) {
        return false;
    }
    if (s.val != t.val) {
        return false;
    } else {
        return isSameTree(s.left, t.left) && isSameTree(s.right, t.right);
    }
}