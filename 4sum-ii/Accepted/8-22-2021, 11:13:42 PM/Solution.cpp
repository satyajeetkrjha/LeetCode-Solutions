// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    
        map <int ,int> m ;
        for(int a:nums1){
            for(int b:nums2){
                ++m[a+b];
            }
        }
        
        int ans =0;
        
        for(int c:nums3){
            for(int d:nums4){
                int sum = -(c+d);
                auto it = m.find(sum);
                if(it!=m.end()){
                   ans += it->second; 
                }
            }
        }
        return ans ;
        
        
        
    }
};