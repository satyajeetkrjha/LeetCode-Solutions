// https://leetcode.com/problems/word-ladder

class Solution {
public:
    queue <string> q ;
    
    map <string ,bool> m ;
    void transform (string word,vector <string> &wordList){
        for(int i =0 ;i<word.size();i++){
            for(char c ='a'; c<='z';c++){
                string temp = word ;
                temp[i] =c ;
                if(m.find(temp)!=m.end()){
                    if(!m[temp]){
                        m[temp] =true ;
                        q.push(temp);
                    }
                }
            }
        }
    }
    
    
    
    
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        q.push(beginWord);
        int level = 1;
        
        for(auto &it:wordList){
            m[it] = false;
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i< sz;i++){
                auto cur = q.front();
                q.pop();
                if(cur == endWord){
                    return level;
                   
                }
                // do all transformations here
                transform(cur ,wordList);
                
            }
            level++;
        }
        return 0;
    }
};