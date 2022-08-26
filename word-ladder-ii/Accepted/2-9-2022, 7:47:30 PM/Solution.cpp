// https://leetcode.com/problems/word-ladder-ii

class Solution {
public:
    
    map <string,vector<string> > adjlist;
    vector <string> currpath ;
    vector <vector <string> > shortestpaths ;
    
    vector<string> findNeighbours(string &word ,unordered_set <string> &wordlist){
        
        vector <string> neighbours ;
        for(int i =0 ;i<word.size();i++){
            char oldchar = word[i];
            for (char c = 'a';c<='z';c++){
                word[i] = c;
                if( c == oldchar || !wordlist.count(word)){
                    continue;
                }
                neighbours.push_back(word);
            }
            word[i] = oldchar;
        }
        return neighbours ;
        
    }
    
    void backtrack(string &source ,string &destination){
        if(source == destination){
            shortestpaths.push_back(currpath);
        }
        for(int i =0 ;i< adjlist[source].size();i++){
            currpath.push_back(adjlist[source][i]);
            backtrack(adjlist[source][i],destination);
            currpath.pop_back();
        }
    }
    
    
    
    void bfs(string beginWord,string endWord ,unordered_set<string>&wordList){
        
        queue <string> q;
        q.push(beginWord);
        
        // remove the root word
        if(wordList.find(beginWord) != wordList.end()){
            wordList.erase(wordList.find(beginWord));
        }
        
        map <string ,int> isEnqueued;
        isEnqueued[beginWord] = 1;
        
        while(!q.empty()){
            vector <string> visited ;
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                string currword = q.front();
                q.pop();
                vector <string> neighbours = findNeighbours(currword,wordList);
                for(auto word:neighbours){
                    visited.push_back(word);
                    adjlist[currword].push_back(word);
                    if(isEnqueued.find(word) == isEnqueued.end()){
                        q.push(word);
                        isEnqueued[word] =1 ;
                    }
                }
            }
            for(int i =0 ;i< visited.size();i++){
                if(wordList.find(visited[i])!=wordList.end()){
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set <string> copiedWords(wordList.begin(),wordList.end());
        
        bfs(beginWord,endWord,copiedWords);
        
        currpath = {beginWord};
        backtrack(beginWord,endWord);
        
        return shortestpaths ;
        
        
    }
};