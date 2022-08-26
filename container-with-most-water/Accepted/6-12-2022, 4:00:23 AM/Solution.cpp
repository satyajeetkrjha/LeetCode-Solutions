// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    
    int maxans= 0;
    
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        if(n==0)
            return 0;
        int left =0 ;
        int right = n-1 ;
        while(left <right){
            int minheight = min(height[left],height[right]);
            int width = right -left ;
            maxans = max(maxans ,width*minheight);
            if(height[left]<height[right]){
                left ++;
            }
            else {
                right --;
            }
        }
        return maxans ;
        
        
        
        
    }
};