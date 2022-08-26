// https://leetcode.com/problems/shortest-word-distance-ii

class WordDistance {
public:
    unordered_map<string ,vector<int> >m;
    WordDistance(vector<string>& wordsDict) {
        for(int i =0;i<wordsDict.size();i++){
            string s= wordsDict[i];
            m[s].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
       
       // sorted vector of indices for first word and second word
       vector<int> first = m[word1];
       vector<int> second =m[word2];
        
       int l1 =0 ;int l2=0 ;
       int dist = INT_MAX;
       while(l1<first.size() && l2<second.size()){
         dist = min(dist,first[l1] >second[l2]?first[l1]-second[l2]:second[l2]-first[l1]);
           if(first[l1]>second[l2]){
               l2++;
           }
           else{
               l1++;
           }  
       }
        return dist ;
        
        
       
        
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */