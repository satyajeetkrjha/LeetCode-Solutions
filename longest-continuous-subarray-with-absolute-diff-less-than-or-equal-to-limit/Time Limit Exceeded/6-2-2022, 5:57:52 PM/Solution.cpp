// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset <int> m;
        
        int j =0 ;
        int ans =1 ;
        
        for(int i =0 ;i< nums.size();i++){
            m.insert(nums[i]);
            
            while(!m.empty() && *m.rbegin() - *m.begin() > limit){
                m.erase(m.find(nums[j++]));
            }
            //cout <<"i is "<< i << endl;
            //cout <<" j is "<< j << endl;
            ans = max(ans ,i-j+1);
            multiset<int>::iterator itr;
            for (itr = m.begin(); itr != m.end(); ++itr) {
                     cout << *itr << " ";
                  }
            cout << endl;
        }
        return ans ;
        
    }
};