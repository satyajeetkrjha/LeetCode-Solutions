// https://leetcode.com/problems/clone-graph

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
        if(node == NULL)
            return node;
        unordered_map<Node*,Node*> m;
        queue<Node*>q ;
        q.push(node);
        m[node]=new Node(node->val);
        while(!q.empty()){
            Node* cur_node=q.front();
            q.pop();
            for(auto nei:cur_node->neighbors){
                if(!m[nei]){ // node has already been created corresponding to old node
                    m[nei] =new Node(nei->val);
                    q.push(nei);
                }
                m[cur_node]->neighbors.push_back(m[nei]);
            }
        }
        return m[node];
    }
};