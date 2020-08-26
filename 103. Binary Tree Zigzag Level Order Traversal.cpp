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


//Recursive O(N^2) Solution Space O(N) Recursion Stack
void printSpiral(struct node* root) 
{ 
    int h = height(root); 
    int i; 
  
    /*ltr -> Left to Right. If this variable is set, 
      then the given level is traversed from left to right. */
    bool ltr = false; 
    for (i = 1; i <= h; i++) { 
        printGivenLevel(root, i, ltr); 
  
        /*Revert ltr to traverse next level in opposite order*/
        ltr = !ltr; 
    } 
} 
  
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level, int ltr) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) { 
        if (ltr) { 
            printGivenLevel(root->left, level - 1, ltr); 
            printGivenLevel(root->right, level - 1, ltr); 
        } 
        else { 
            printGivenLevel(root->right, level - 1, ltr); 
            printGivenLevel(root->left, level - 1, ltr); 
        } 
    } 
}