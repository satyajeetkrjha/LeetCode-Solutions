// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq ;
        vector <int> res ;
        // we are going to store numbers in a decreasing order in our deque thus this while
        for(int i =0 ;i<k;i++){
            while(!dq.empty() && dq.back() <nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        
        for(int i = k ;i <nums.size();i++){
            
            
            if(dq.front()  == nums[i-k]){
                dq.pop_front();    
            }
            
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            res.push_back(dq.front());
        }
        return  res ;
        
        
    }
};