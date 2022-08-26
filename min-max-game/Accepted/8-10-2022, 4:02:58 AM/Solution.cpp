// https://leetcode.com/problems/min-max-game

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        while(nums.size()>1){
            vector <int> temp ;
            bool flag = false;
            for(int i =0 ;i<nums.size();i+=2){
                 int x  = nums[i];int y= nums[i+1];
                 if(!flag){
                     temp.push_back(min(x,y));
                 }else{
                     temp.push_back(max(x,y));
                 }
                 flag = !flag;    
            }
            nums= temp;
        }
        return nums[0];
    }
};