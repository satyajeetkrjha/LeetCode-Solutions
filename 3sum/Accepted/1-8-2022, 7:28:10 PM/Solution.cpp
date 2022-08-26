// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int>> res;
        sort(nums.begin(),nums.end());
        int l =0 ;
        int r = 0;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            l = i+1;
            r = n-1;
            while( l <r){
             int sum = nums[i]+nums[l]+nums[r] ;
            if( sum == 0){
                vector <int> temp ;
                temp.push_back(nums[i]);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                res.push_back(temp);
                int numsleft = nums[l];
                int numsright = nums[r];
                while(numsleft == nums[l] && l<r){
                    l++;
                }
                while(numsright == nums[r] && l <r ){
                    r--;
                }
            }
            else if (nums[i]+ nums[l]+nums[r] <0){
                l++;
            }
            else{
                r--;
            }
        }
            while(i+1 < nums.size() && nums[i] == nums[i+1]){
                i++;
            }   
        }
        return res;
        
        
    }
};