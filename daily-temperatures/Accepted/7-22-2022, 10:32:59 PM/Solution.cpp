// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
       vector <int> res(nums.size(),0);
       stack <pair <int ,int> > st ;
       for(int i =nums.size()-1 ;i>=0;i--){
           while(!st.empty() && nums[i] >= st.top().first){
               st.pop();
           }
           res [i] = st.empty() ? 0 : st.top().second - i;
           st.push({nums[i],i});
       } 
        return res ;
    }
};