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


//// Iterative function to print right view of given binary tree
//Time O(n) Space O(n)
void rightView(Node* root)
{
	// return if tree is empty
	if (root == nullptr)
		return;

	// create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

	// pointer to store current node
	Node* curr = nullptr;

	// loop till queue is empty
	while (!queue.empty())
	{
		// calculate number of nodes in current level
		int size = queue.size();
		int i = 0;

		// process every node of current level and enqueue their
		// non-empty right and right child to queue
		while (i++ < size)
		{
		   curr = queue.front();
		   queue.pop_front();

		   // if this is last node of current level, print it
		   if (i == size)
				cout << curr->key << " ";

		   if (curr->left)
				queue.push_back(curr->left);

		   if (curr->right)
				queue.push_back(curr->right);
		}
	}
}


//Linear Time, Constant Space
void rightView(Node *root, int level, int &last_level)
{
	// base case: empty tree
	if (root == nullptr)
		return;

	// if current node is last node of current level
	if (last_level < level)
	{
		// print the node's data
		cout << root->key << " ";

		// update last level to current level
		last_level = level;
	}

	// recur for right and left subtree by increasing level by 1
	rightView(root->right, level + 1, last_level);
	rightView(root->left, level + 1, last_level);
}

// Function to print right view of given binary tree
void rightView(Node *root)
{
	int last_level = 0;
	rightView(root, 1, last_level);
}