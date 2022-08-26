// https://leetcode.com/problems/word-search-ii

int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};

struct Node{
    Node* links[26];
    string* word;
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put (char ch ,Node* node){
        links[ch-'a']  =node;
    }    
};



class Solution {

    private:
    Node* root ;
    vector <string> ans;
    
public:
   

    Solution(){
        root = new Node();
    }
     
    void insert( string &word){
        Node* node = root;
        int n = word.size();
        for(int i =0 ;i<n;i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->word = &word;
        cout <<*node->word <<endl;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        for(int i =0 ;i<words.size();i++){
           insert(words[i]);
        }
        
        int n = board.size();
        int m = board[0].size();
        
        Node* node = root ;
       
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m ;j++){
                dfs(board,i,j,node);
            }
        }
    
        return ans;
        
    }
    
    void dfs(vector<vector<char>>& board ,int r ,int c,Node* node){
        
        if( r < 0 || c <0 ||  r>= board.size() || c>= board[0].size() || board[r][c]  == '#'|| node->containsKey(board[r][c]) ==NULL){
            return ;
        }
        char originalchar = board[r][c];
        node = node->get(originalchar);
        if(node->word!=NULL){
            ans.push_back(*node->word);
            node->word =NULL;
        }
        board[r][c] = '#';
        for(int k =0;k<4;k++){
            dfs(board,r+dx[k],c+dy[k],node);
        }
        board[r][c] = originalchar;
        
        
    }
    
    
    
    
    
};