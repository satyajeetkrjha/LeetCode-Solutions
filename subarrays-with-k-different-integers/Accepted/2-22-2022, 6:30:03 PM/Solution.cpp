// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    
    
    int atmost(vector <int> &nums ,int k){
        int left =0 ;
        int right =0 ;
        int count =0 ;
        map <int ,int> m;
        int n = nums.size();
        
        while(right <n){
            if(m.find(nums[right]) == m.end()){
                m[nums[right]] =1;
            }
            else{
                m[nums[right]]++;
            }
    
          while( m.size() > k){
             m[nums[left]] --;
             if(m[nums[left]] ==0){
                 m.erase(nums[left]);
                }
              left++;
            }  
            count += right -left+1;
            right++;
        
        }
        return count ;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};