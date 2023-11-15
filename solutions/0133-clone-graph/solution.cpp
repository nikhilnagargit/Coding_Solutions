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
    void dfs(Node* node,Node* copynode,unordered_map<int,Node*>&m){
        for(auto neighbor:node->neighbors){
            Node* copyneighbor;
            if(m.find(neighbor->val)==m.end()){
                copyneighbor = new Node(neighbor->val);
                m[neighbor->val] = copyneighbor;
                dfs(neighbor,copyneighbor,m);
            }
            else{
                copyneighbor = m[neighbor->val];
            }
            copynode->neighbors.push_back(copyneighbor);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        unordered_map<int,Node*> m;
        Node* copynode = new Node(node->val);
        m[node->val] = copynode;
        dfs(node,copynode,m);
        return copynode;
    }
};
