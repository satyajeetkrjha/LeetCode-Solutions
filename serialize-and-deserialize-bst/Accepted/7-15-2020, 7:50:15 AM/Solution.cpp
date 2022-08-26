// https://leetcode.com/problems/serialize-and-deserialize-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string res;
       queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           TreeNode* cur =q.front();
            q.pop();
            if(cur ==NULL)
                return res;
            res+=to_string(cur->val)+",";
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }           
        }
        cout<<"res is "<<res<<endl;
        return res;
    }
    TreeNode* construct(TreeNode* root,int val){
        if(root == NULL){
            root= new TreeNode(val);
            return root;
        }
        if(val >root->val){
            root->right =construct(root->right,val);
        }
        else if(val <root->val){
            root->left =construct(root->left,val);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<"data"<<data<<endl;
        TreeNode* root =NULL;
        int temp=0;
        for(int i =0;i<data.size();i++){
            if(data[i]!=','){
                temp= temp*10+(int)(data[i]-'0');
            }
            if(data [i]==','){
                root=construct(root,temp);
                temp =0;
            }
        }
        return root;   
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));