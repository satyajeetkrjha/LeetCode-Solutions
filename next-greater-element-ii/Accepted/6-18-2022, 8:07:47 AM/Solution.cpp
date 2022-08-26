// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        stack <int> st ;
        int n = nums.size();
        vector <int> res(n);
        for(int i = n-1;i>=0 ;i--){
            
            while(!st.empty() && nums[i] >=st.top()){
                st.pop();
            }
             res[i] = st.empty() ? -1 :st.top();
             st.push(nums[i]);
        }
        for(int i = n-1;i>=0 ;i--){
            if(res[i]  == -1){
                while(!st.empty() && nums[i] >= st.top()){
                  st.pop();
                }
                res[i] = st.empty() ? -1 :st.top();
            }
            st.push(nums[i]);
        }
        return res ;
    
         
        
        
        
        
    }
};