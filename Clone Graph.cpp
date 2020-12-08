/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* helper(Node* node, unordered_map<int, Node*> &visited) {
        if(node == NULL) {
            return NULL;
        }
        
        Node *newNode = new Node(node->val);
        visited[node->val] = newNode;
        
        for(auto var : node->neighbors) {
            if(visited.find(var->val) == visited.end()) {
                Node* nextNode = helper(var, visited);
                newNode->neighbors.push_back(nextNode);
            }
            else {
                //Important
                newNode->neighbors.push_back(visited[var->val]);
            }
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> visited;
        return helper(node, visited);
    }
};