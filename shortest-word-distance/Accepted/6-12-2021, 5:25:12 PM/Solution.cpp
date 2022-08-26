// https://leetcode.com/problems/shortest-word-distance

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int min_dist =INT_MAX;
        int w1 =-1;
        int w2 =-1;
        // w1 and w2 stores the index of the words 
        for(int i=0;i<wordsDict.size();i++){
            if(wordsDict[i] == word1){
                w1 =i;
            }
            else if (wordsDict[i] ==word2){
                w2=i;
            }
            
            if(w1 !=-1 && w2 !=-1){
                min_dist = min(min_dist,abs(w1-w2));
            }
        }
        cout<<"min_dist is "<<min_dist<<endl;
        return min_dist ;
    }
};