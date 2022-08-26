// https://leetcode.com/problems/concatenated-words



struct Node{
   
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put (char ch,Node* node){
        links[ch-'a'] =node;
    }
    void markEnd(){
        flag = true;
    }
    
    bool endsWith(){
        return flag ;
    }
    
};


class Solution {
    
private:
    Node* root;
    
public:
     Solution(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root ;
        for(int i = word.size()-1;i>=0;i--){
           char ch = word[i];
            if(!node->containsKey(ch)){
               node->put(ch ,new Node());   
            }
            node = node->get(ch);
            
        }
        node->markEnd();
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> ret ;
        if(words.size() ==0){
            return ret ;
        }
        
        sort(words.begin(),words.end(),[](const string& w1,const string& w2){
            return w1.size()<=w2.size();
        });
        
        
        
        for(auto &word:words){
            
            
           
            Node *node = root;
        
            vector <bool> dp(word.size()+1,0);
            dp[0] =1;
            
            for(int i =0 ;i<word.size();i++){
                node = root ;
                for(int j = i;j>=0 ;j--){
                    char ch = word[j];
                    if(!node->containsKey(ch)){
                        break;
                    }
                    node =node->get(ch);
                    if(dp[j] && node->endsWith()){
                        dp[i+1] = true;
                        break;
                    }        
                }
            }
            if(dp[word.size()])
                ret.push_back(word);
            
            insert(word);
            
        }
        
        return ret ;
             
    }
};