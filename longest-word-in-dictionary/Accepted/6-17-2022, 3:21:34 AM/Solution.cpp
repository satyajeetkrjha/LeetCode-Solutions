// https://leetcode.com/problems/longest-word-in-dictionary


struct Node{
   Node* links[26];
   bool flag = false ;
   
   void setEnd(){
        flag = true;
   }
    
   bool isEnd(){
       return flag;
   } 
   
    bool containsKey(char ch){
        return links[ch-'a']!=NULL  ;
    }
    
    void put(char ch ,Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
};










class Solution {
    Node* root ;
public:
    Solution(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root ;
        for(char ch :word){
            if(!node->containsKey(ch)){
                node->put(ch ,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }   
    
    bool search(string word){
        int count =0;
        Node* node = root ;
        for(auto &ch :word){
            node = node->get(ch);
            if(node->isEnd()){
                count ++;
            }
        }
        return count == word.size();
    }
    
    
    
    string longestWord(vector<string>& words) {
        
        for(auto &word :words){
            insert(word);
        }
        
        string ans ;
        for(int i =0 ;i< words.size();i++){
            string word = words[i];
            bool find = search(word);
            if(find && word.size() > ans.size()){
                ans = word;
            }
            else if(find && word.size() == ans.size()){
                ans = min(ans ,word);
            }
        }
        return ans ;
    
    }
};