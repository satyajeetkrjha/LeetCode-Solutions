// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int ,int> m ;
        for(auto &it: arr){
            cout <<"it is "<< it << endl;
            m[it]++;
        }
        int c =0;
        for(auto &it:m){
            cout <<"first "<< it.first << endl;
            if(it.second ==1){
                c++;
            }
        }
        if(c ==1 ){
            return true;
        }
        return false;
    }
};