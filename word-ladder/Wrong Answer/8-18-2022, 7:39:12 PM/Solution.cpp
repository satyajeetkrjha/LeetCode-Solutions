// https://leetcode.com/problems/word-ladder

class Solution {
public:
    queue <string> q ;
    map <string ,bool >m ;
    
    void transform(string word){
        for(int i =0 ;i<word.size();i++){
            for(char c='a';c<='z';c++){
                 string temp = word;
                 temp[i] = c;
                 if(m.find(temp)!=m.end()){
                     if(m[temp] == false){
                         m[temp] = true;
                         q.push(temp);
                     }
                 }
            }
        }
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        for(int i =0;i<wordList.size();i++){
            m[wordList[i]] = false ;
        }
        if(beginWord == endWord)
            return 0;
        q.push(beginWord);
        int dist =1;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                if(cur == endWord)
                    return dist;
                 transform(cur);
            }
           dist++;
        }
        return dist ;
    }
};