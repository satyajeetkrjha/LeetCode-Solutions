// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

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
        queue <TreeNode*> q;
        q.push(root);
        string res ="";
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                res +="NULL ";
            }
            else{
                res +=to_string(temp->val)+" ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout <<"res is "<< res <<endl;
        return res ;
        
    }
    vector <string > split(string &s){
        int start =0;
        vector <string > res ;
        for(int i =0 ;i<s.size();i++){
            if(s[i] == ' '){
                res.push_back(s.substr(start,i-start));
                start = i+1;
            }
        }
        return res ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string > res = split(data);
        for(int i =0 ;i<res.size();i++){
            cout << res[i]<< " ";
        }
        cout <<endl;
        if(res[0] == "NULL"){
            return NULL;
        }
        queue <TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(res[0]+string()));
        int i =0 ;
        q.push(root);
        while( i < res.size() && !q.empty()){
            auto temp = q.front();
            q.pop();
            if(res[++i]!="NULL"){
                temp->left = new TreeNode(stoi(res[i]+string()));
                q.push(temp->left);
            }
             if(res[++i] != "NULL"){
                temp->right = new TreeNode(stoi(res[i] + string()));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));