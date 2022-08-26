// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map <int ,int > m ;
        for(auto it:arr){
            m[it]++;
        }
        multimap <int ,int,greater<int> > mm ;
        for(auto [key,value]:m){
            mm.insert({value,key});
        }
        int counter =0 ;
        int sz = arr.size();
        for(auto it :mm){
             sz= sz - it.first;
             counter++;
            if(sz <=(arr.size()/2)){
                 return counter ;
            }
        }
        return counter ;
        
    }
};