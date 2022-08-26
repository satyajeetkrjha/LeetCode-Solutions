// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int ,int> m ;
        for(auto &it: arr){
            m[it]++;
        }
        int c =0;
        for(auto it:m){
            if(it.first ==1){
                c++;
            }
        }
        if(c >1){
            return false;
        }
        return true;
    }
};