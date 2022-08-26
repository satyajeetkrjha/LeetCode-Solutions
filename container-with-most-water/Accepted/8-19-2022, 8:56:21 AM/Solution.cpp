// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
      int left =0 ;
      int width =0;
      int right = height.size()-1;
      int minheight =0;
      int maxarea =0;  
      while(left <right){
          minheight = min(height[left],height[right]);
          width = right -left;
          maxarea = max(maxarea,(width*minheight));
          if(height[left] <height[right]){
              left++;
          }
          else
              right--;
      }  
        return maxarea ;
    }
};