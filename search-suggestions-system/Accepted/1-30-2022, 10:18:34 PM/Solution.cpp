// https://leetcode.com/problems/search-suggestions-system


struct Node{
    
    Node* links[26];
    bool flag ;
    
    void setEnd(){
        flag = true;
    }
    
    bool getEnd(){
        return flag ;
    }
    
    void put(char ch ,Node* node){
        links[ch-'a'] = node;
    }
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
};





class Solution {
    
    private :
        Node* root ;
        vector <vector <string> > results ;
    
public:
    
    Solution(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root ;
        for(int i =0 ;i<word.size();i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    void dfs(Node* node ,string &word, vector<string> &res){
        if(res.size() == 3){
            return;
        }
        if(node->getEnd()){
            res.push_back(word);
        }
        
        for( char c = 'a';c<='z';c++){
            if(node->containsKey(c)){
                word += c;
                //node = node->get(c);
                dfs(node->get(c) ,word,res);
                word.pop_back();
            }
        }
        
    }
    
    vector<string> moveToPrefix(string word){
        // carry the root forward to the prefix first 
        Node* node = root ;
        vector<string> res;
        for(int i =0 ;i<word.size();i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                return res;
            }
            node = node->get(ch);
        }
        dfs(node,word,res);
        return res ;
        
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        for(int i =0 ;i<products.size();i++){
            insert(products[i]);
        }
        
        string prefix ;
        for(int i =0;i<searchWord.size();i++){
            prefix = prefix+searchWord[i];
            results.push_back(moveToPrefix(prefix));
        }
        
        
        return results ;
        
        
    }
};