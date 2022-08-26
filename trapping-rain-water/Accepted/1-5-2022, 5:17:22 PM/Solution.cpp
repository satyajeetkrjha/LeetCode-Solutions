// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& heights) {
        int leftmax =0 ;
        int rightmax = 0 ;
        int left =0 ;
        int right = heights.size() -1;
        int res =0;
        while(left <right){
            leftmax = max(leftmax,heights[left]);
            rightmax = max(rightmax ,heights[right]);
            if(leftmax <rightmax){
                res += leftmax - heights[left];
                left++;
            }
            else{
                res += rightmax -heights[right];
                right--;
            }
        }
        return res ;
    }
};