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
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> visited;
        queue<Node*> varQueue;
        varQueue.push(node);
        
        Node* Clone = new Node(node->val);
        visited[node] = Clone;
        
        while(!varQueue.empty()) {
            Node* temp = varQueue.front();
            varQueue.pop();
            for(Node* neigh : temp->neighbors) {
                if(visited.find(neigh) == visited.end()) {
                    visited[neigh] = new Node(neigh->val);
                    varQueue.push(neigh);
                }
                visited[temp]->neighbors.push_back(visited[neigh]);
            }
        }
        return Clone;
    }
};