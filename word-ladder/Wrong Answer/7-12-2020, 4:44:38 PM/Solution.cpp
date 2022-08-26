// https://leetcode.com/problems/word-ladder

class Solution {
public:
     map<string ,int> visited;
     queue<string> q;
    void transform(vector<string>& wordList, string word){
      for(int i=0;i<word.size();i++){
          for(char c ='a';c<='z';c++){
              string temp = word;
              temp[i]=c;
              string newword =temp;
              //cout<<"newword is now "<<newword<<endl;
              if(visited.find(newword)!=visited.end()){
                  if(visited[newword]==0){
                  cout<<"neeword pushed in queue now is "<<newword<<endl;
                  q.push(newword);
                  visited[newword]++;
                  }
                  
              }
          }
      }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        for(int i=0;i<wordList.size();i++){
            string word =wordList[i];
            visited[word]=0;
        }
        q.push(beginWord);
        visited[beginWord]++;
        int level=1;
        while(!q.empty()){
            int sz= q.size();
            cout<<"size of queue is "<<sz<<endl;
            for(int i=0;i<sz;i++){
                string word =q.front();
                q.pop();
                cout<<"word is "<<word<<endl;
                if(word == endWord)
                    return level;
                //do all possible transformations by changing one word at a time in te word taken out from the queue
                transform(wordList,word);
            }
            level++;
        }
        return level;
    }
};