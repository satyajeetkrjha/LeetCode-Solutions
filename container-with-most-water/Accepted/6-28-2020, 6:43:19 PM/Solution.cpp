// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
       if(height.size()==0)
           return 0;
       int left =0;
       int right =height.size()-1;
       int maxArea =-INT_MAX;
       while(left<right){
           maxArea =max(maxArea, min(height[left],height[right])*(right-left));
           if(height[left]<height[right]){
               left++;
           }
           else
               right--;
       }
        return maxArea;
    }
};