// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set <int> s ;
        for(int i =0 ;i<nums.size();i++){
           auto it = s.find(nums[i]);
            if(it!=s.end())
                return true ;
            /*
            for(auto &it:s){
                cout << it << " ";
            }
            */
            s.insert(nums[i]);
            cout << endl;
            if(s.size() >k){
                s.erase(nums[i-k]);
            }
        }
        return false ;
    }
};