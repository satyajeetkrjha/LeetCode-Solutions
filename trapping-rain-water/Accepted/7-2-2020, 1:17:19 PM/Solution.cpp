// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0; 
        int leftMax=0;
        int rightMax =0;
        int left =0;
        int right =height.size()-1;
        int ans=0;
        while(left<right){
            leftMax =max(leftMax,height[left]);
            rightMax =max(rightMax,height[right]);
            if(leftMax<rightMax){
                ans+=leftMax-height[left];
                left++;
            }
            else{
                ans +=rightMax-height[right];
                right--;
            }
        }
        return ans;
    }
};