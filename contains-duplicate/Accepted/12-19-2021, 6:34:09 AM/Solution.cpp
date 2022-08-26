// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      map <int ,int> m;
      for(int i =0 ;i<nums.size();i++){
          int x = nums[i];
          m[x]++;
      }
        for(auto it :m){
            cout <<"firts .."<< it.first <<endl;
            cout <<"second .."<< it.second << endl;
            if(it.second >1){
                return true;
            }
        }
        return false;
    }
};