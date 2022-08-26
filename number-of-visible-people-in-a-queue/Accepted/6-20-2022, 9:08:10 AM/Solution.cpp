// https://leetcode.com/problems/number-of-visible-people-in-a-queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        
        int n = nums.size() ;
        stack <int> st ;
        vector <int> res (n,0);
        
        for(int i = n-1 ;i>=0 ;i--){
        
            // for all elements smaller than the current element you add 1
            while(!st.empty() && nums[i] > st.top()){
                 st.pop();
                res[i] = res[i] +1;
            }
            // means there is an element greater than ur current nums[i] so +1 tall guy 
            if(!st.empty()){
                res[i] ++;
            }
           st.push(nums[i]);
        }
        
        return res ;
         
        
    }
};