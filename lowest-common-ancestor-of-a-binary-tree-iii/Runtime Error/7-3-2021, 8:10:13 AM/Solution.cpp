// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int depth(Node* root){
        int depth =0;
        while(root!=NULL){
            root =root->parent;
            depth++;
        }
        return depth;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int d1 = depth(p);
        int d2 =  depth(q);
        int diff = d1-d2;
        if(diff >0){ // move node p upwrads by this diff
            while(diff >0){
                p = p->parent;
            }
        }
        else {
            diff = -diff;
            while(diff >0){
                q = q->parent;
            }
        }
        
        // now both are at same level
        while(p!=NULL && q!=NULL){
             if(p ==q) 
                 return p;
             p = p->parent ;
             q=  q->parent ; 
        }
        return NULL;
      
      }
};