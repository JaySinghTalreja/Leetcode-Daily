/*

Input: Root of below tree
         2
       /   \
     7      5
    / \    / \
   8   6   7   9
      / \    /  \
     1  11  4    10 


*/
class Solution{
    unordered_map<int, int> levelSum;
    void solve(TreeNode *root, int level = 0) {
        if(root == NULL) {
            return;
        }
        if(!root->left && !root->right) {
            auto it = find(levelSum.begin(), leveSum.end(), level);
            if(it == levelSum.end()) {
                levelSum[level] = root->data;
            }
            else{
                levelSum[level] += root->data;
            }

            
            return;
        }
        solve(root->left, level+1);
        solve(root->right, level+1);
    }

    int sum(TreeNode* root) {
        solve(root);
        int product = 1;
        for(auto var : levelSum) {
            product *= var.second;
        }
        return product == 1 ? levelSum.size() == 0 ? product = 0: product;
    }
}



//BFS Based Soluton - No Extra Space
int sumAndMultiplyLevelData(Node* root) 
{ 
    // Tree is empty 
    if (!root) 
        return 0; 
  
    int mul = 1; /* To store result */
  
    // Create an empty queue for level order tarversal 
    queue<Node*> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    // Do level order traversal of tree 
    while (1) { 
        // NodeCount (queue size) indicates number of Nodes 
        // at current lelvel. 
        int NodeCount = q.size(); 
  
        // If there are no Nodes at current level, we are done 
        if (NodeCount == 0) 
            break; 
  
        // Initialize leaf sum for current level 
        int levelSum = 0; 
  
        // A boolean variable to indicate if found a leaf 
        // Node at current level or not 
        bool leafFound = false; 
  
        // Dequeue all Nodes of current level and Enqueue all 
        // Nodes of next level 
        while (NodeCount > 0) { 
            // Process next Node  of current level 
            Node* Node = q.front(); 
  
            /* if Node is a leaf, update sum at the level */
            if (isLeaf(Node)) { 
                leafFound = true; 
                levelSum += Node->data; 
            } 
            q.pop(); 
  
            // Add children of Node 
            if (Node->left != NULL) 
                q.push(Node->left); 
            if (Node->right != NULL) 
                q.push(Node->right); 
            NodeCount--; 
        } 
  
        // If we found at least one leaf, we multiply 
        // result with level sum. 
        if (leafFound) 
            mul *= levelSum; 
    } 
  
    return mul; // Return result 
} 
  