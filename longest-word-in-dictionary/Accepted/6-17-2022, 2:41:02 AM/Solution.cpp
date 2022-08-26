// https://leetcode.com/problems/longest-word-in-dictionary


struct Node{
   Node* links[26];
   bool flag = false ;
    
   void setEnd(){
       flag = true;
   }
   bool isEnd(){
       return flag ;
   }
   
    void put (char ch ,Node* node){
        links[ch-'a'] =node;
    }
    
    Node* get (char ch){
        return links[ch-'a'];
    }
    
    bool containsKey(char ch){
        return links[ch-'a'] !=NULL;
    }    
};

class Solution {
private:
    Node* root ;
    
    
    
public:
    Solution(){
       root = new Node();
    }
    
    void insert(string word){
        Node* node = root ;
        int n = word.size();
        for(int i =0 ;i< n;i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node ->get(ch);
        }
        node->setEnd();
    }
    
    
    bool search (string word){
        int count = 0 ;
        Node *node = root ;
        for(int i =0 ;i< word.size();i++){
            char ch = word[i] ; // each char 
            node = node ->get(ch);
            if(node->isEnd())
                count ++;
                
        }
        return word.size() == count ;
    }
    
    
    
    string longestWord(vector<string>& words) {
       
        string ans ;
        for(int i =0 ;i< words.size();i++){
            string word = words[i];
            insert(word);
        }
        
        for(int i =0  ;i< words.size();i++){
            string word = words[i];
            if(ans.size()  > word.size()) 
                continue ;
            
            bool found = search(word); 
            if(found && word.size()> ans.size()){
                ans  = word ;
            }
            else if (found && word.size() == ans.size()){
                ans = min(ans,word) ; // pick lexicographically smaller word
            }
        }
        return ans ;    
    }
};