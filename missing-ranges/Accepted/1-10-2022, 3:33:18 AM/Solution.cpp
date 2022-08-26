// https://leetcode.com/problems/missing-ranges

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector <string> res ;
        int prev = lower -1;
      //  cout <<"sz is "<< nums.size()<< endl;
        for(int i =0 ;i<=nums.size();i++){
            int curr =  i < nums.size() ?  nums[i] :upper+1;
            if(prev+1 <= curr -1){
                res.push_back(format(prev+1,curr-1));
            }
            prev = curr ;
           // cout <<"i is "<< i << endl;
        }
        return res ;
    }
    
    string format(int low ,int high){
        if(low == high){
            return to_string(low);
        }
     return to_string(low)+"->" + to_string(high);
    }
};