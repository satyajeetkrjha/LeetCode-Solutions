// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue < pair<Node*,int> > q;
        q.push(make_pair(root,1));
        int maxval =0;
        if(root ==NULL)
            return maxval;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair <Node*,int> p = q.front();
                q.pop();
                maxval =max(maxval,p.second);
                Node *cur =p.first;
                vector <Node*> child = cur->children;
                for(int j=0;j<child.size();j++){  
                    q.push(make_pair(child[j],p.second+1));
                }
               
                }
            }
        
        return maxval;
        
    }
};