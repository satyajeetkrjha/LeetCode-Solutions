// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0 ;
        int right = height.size()-1;
        int maxarea =0;
        if (height.size() == 0) return 0;
        while(left <right){
            int minheight = min(height[left],height[right]);
            int width = right - left ;
            maxarea = max(maxarea ,(minheight*width));
            if(height[left]<height[right]){
                left++;
            }
            else 
                right --;
        }
        return maxarea ;
    }
};