// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue <pair <int ,int> > pq;
       vector <int> ans;
        for(int i=0;i< nums.size();i++){
            
            // if root element is out of the sliding window then just pop it
            while(!pq.empty() && pq.top().second <=(i-k)){
                  pq.pop();
            }
               pq.push(make_pair(nums[i],i));
              // rem that you will fill       
             if(i>=k-1){
                 ans.push_back(pq.top().first);
             }
                      
                    
     }
    return ans ;
};
        };