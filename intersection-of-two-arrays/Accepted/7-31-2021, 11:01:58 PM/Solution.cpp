// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> s (nums1.begin(),nums1.end());
        vector <int> v;
         for(int i =0 ;i<nums2.size();i++){
             int val = nums2[i];
             if(s.count(val)){
                 v.push_back(val);
                 s.erase(val);
             }
         }
        return v;
    }
};