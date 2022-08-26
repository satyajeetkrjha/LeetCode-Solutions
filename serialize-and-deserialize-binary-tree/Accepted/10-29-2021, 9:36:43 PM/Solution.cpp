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
        string res = "";
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                res += "NULL ";
            }
            else{
                res+= to_string(temp->val)+ " ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout << " res is "<< res <<endl;
        return res ;
    }

    vector <string> split( string s){
       vector <string > res ;
        int start =0 ;
       for(int i =0 ;i< s.size();i++){
           if(s[i] == ' '){
               cout <<"start is "<< start <<endl;
               cout << "i-start is "<< i-start <<endl;
               cout <<"substring is "<< s.substr(start,i-start)<<endl;
               res.push_back(s.substr(start,i-start)); // substring of length i-start fro, start index
               start = i+1;
           }
       } 
        return res;  
     }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       vector <string > res = split(data);
        queue <TreeNode*> q;
        if(res[0] == "NULL") return NULL;
        int value = stoi(res[0]);
        cout<<"value is "<<value <<endl;
        TreeNode* root = new TreeNode(stoi(res[0]));
        int i =0 ;
        q.push(root);
        while( i< res.size() && !q.empty()){
            auto temp = q.front();
            q.pop();
            if(res[++i]!="NULL"){
                temp->left = new TreeNode(stoi(res[i]));
                q.push(temp->left);
            }
            if(res[++i]!="NULL"){
                temp->right = new TreeNode(stoi(res[i]));
                q.push(temp->right);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));