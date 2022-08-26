// https://leetcode.com/problems/range-addition

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
       vector <int> result(length ,0);
        for(int i =0 ;i<updates.size();i++){
            vector <int> v = updates[i];
            int start= v[0];int end = v[1];int val = v[2];
            result[start]+= val;
            if(end <length-1){
                result[end+1]-= val;
            }
        }
        partial_sum(result.begin(),result.end(),result.begin());
        
        return result ;
    }
};