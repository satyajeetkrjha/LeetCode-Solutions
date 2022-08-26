// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> maxleft ,maxright ;
        maxleft.resize(n);maxright.resize(n);
        
        int ans =0;
        maxleft[0] = height[0];
        for(int i =1 ;i<n;i++){
            maxleft[i] = max(maxleft[i-1],height[i]);
        }
        
        maxright[n-1] =height[n-1];
        for(int i = n-2 ;i>=0 ;i--){
            maxright[i] = max(maxright[i+1],height[i]);
        }
        
        for(int i =0 ;i<n;i++){
            ans += min(maxright[i],maxleft[i]) - height[i];
        }
        return ans ;
        
        
        
        
    }
};