//Recursive DFS O(N)


#include <iostream>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node {
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node and return it
	if (root == nullptr)
		return newNode(key);

	// if given key is less than the root node, recur for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

	// if given key is more than the root node, recur for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}

// Helper function to find minimum value node in given BST
Node* findMinimum(Node* root)
{
	while (root->left)
		root = root->left;

	return root;
}

// Recursive function to find inorder successor for given key in a BST
// Note that successor 'succ' is passed by reference to the function
void findSuccessor(Node* root, Node*& succ, int key)
{
	// base case
	if (root == nullptr) {
		succ = nullptr;
		return;
	}

	// if node with key's value is found, the successor is minimum value
	// node in its right subtree (if any)
	if (root->data == key)
	{
		if (root->right)
			succ = findMinimum(root->right);
	}
	// if given key is less than the root node, recur for left subtree
	else if (key < root->data)
	{
		// update successor to current node before recursing in left subtree
		succ = root;
		findSuccessor(root->left, succ, key);
	}

	// if given key is more than the root node, recur for right subtree
	else
		findSuccessor(root->right, succ, key);
}

int main()
{
	/* Construct below tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
	*/

	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	Node* root = nullptr;
	for (int key : keys)
		root = insert(root, key);

	// find in-order successor for each key
	for (int key : keys)
	{
		Node* prec = nullptr;
		findSuccessor(root, prec, key);

		if (prec != nullptr)
			cout << "Successor of node " << key << " is " << prec->data;
		else
			cout << "Successor doesn't exists for " << key;

		cout << '\n';
	}

	return 0;
}


//Refer Techie Delight for Inputs