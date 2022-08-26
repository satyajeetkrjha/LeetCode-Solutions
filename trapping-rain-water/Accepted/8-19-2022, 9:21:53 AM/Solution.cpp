// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> leftheight(n);
        vector <int> rightheight(n);
        leftheight[0] = height[0];
        for(int i =1 ;i<height.size();i++){
            leftheight[i]  =max(height[i],leftheight[i-1]);
        }
        rightheight[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            rightheight[i] = max(height[i],rightheight[i+1]);
        }
        int ans =0;
        for(int i =0 ;i<n;i++){
            ans += (min(leftheight[i],rightheight[i]))-height[i];
        }
        return ans ;
    }
};