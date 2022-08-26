// https://leetcode.com/problems/word-ladder

class Solution {
public:
     map < string ,int> visited ;
      queue <string> q ;
     void transform (string word,vector<string>& wordList){
            // make changes 
            for(int i =0 ;i< word.size();i++){
                  for(char c = 'a';c<='z';c++){
                      string temp = word ;
                      temp[i] = c;
                      // temp exists in the wordlist and is not visited yet
                      if(visited.find(temp)!= visited.end()){
                         if(visited[temp] == 0){
                             visited[temp] =1;
                             q.push(temp);
                         }
                      }
                  }
            }
        }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)        
    {
     
      
        for(int i =0 ;i< wordList.size();i++){
            visited[wordList[i]] =0 ;
        }
        q.push(beginWord);
        
        int level =0 ;
        bool flag = false ;
        
       
        
        visited[beginWord]++;
     
        while(!q.empty()){
            int sz = q.size();
            level ++;
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                
                if( cur == endWord){
                    flag = true ;
                    return level ;
                }
                
                // make all possible changes 
                transform(cur,wordList);
            }
        }
        return 0; 
    }
};