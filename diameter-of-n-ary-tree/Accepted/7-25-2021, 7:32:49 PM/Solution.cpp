// https://leetcode.com/problems/diameter-of-n-ary-tree

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
    int res = 0;
    int maximumdepth(Node* root){
        if(root->children.size() == 0)
            return 0;
        
        int maxheight1 = 0 ;int maxheight2 = 0;
        for(Node* child: root->children ){
            // cout<<"child->val is "<<child->val<<endl;
            int parentheight = maximumdepth(child)+1;
            // cout<<"parentheight is "<<parentheight <<endl;
            if(parentheight >maxheight1){
                maxheight2 = maxheight1;
                maxheight1 = parentheight;
            }
            else if(parentheight >maxheight2){
                maxheight2= parentheight;
            }
            int distance = maxheight1 +maxheight2;
            res = max(res,distance);
        }
        return maxheight1;
        
    }
    int diameter(Node* root) {
        maximumdepth(root);
        return res ;
    }
};