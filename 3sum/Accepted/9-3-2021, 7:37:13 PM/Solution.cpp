// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector <int> > ans ;
        int n = nums.size();
        sort(nums.begin(),nums.begin()+n);
        for(int i =0 ;i<n;i++){
           int l = i+1;
           int r = n-1;
            int x = nums[i];
           while( l<r){
               vector <int> v;
               int sum = nums[i]+ nums[l]+ nums[r];
               if(sum ==0){
                   v.push_back(nums[i]);
                   v.push_back(nums[l]);
                   v.push_back(nums[r]);
                   ans.push_back(v);
                   v.clear();
                   int leftval = nums[l];
                   int rightval = nums[r];
                   while(leftval == nums[l] && l<r){
                       l++;
                   }
                   while(rightval == nums[r] && l <r){
                       r--;
                   }
               }
               else if (nums[i]+ nums[l]+ nums[r]<0){
                   l++;
               }
               else {
                   r--;
               }
           }
               while(i+1 <n && nums[i] == nums[i+1] ){
                   i++;
               }
           } 
        return ans;
    }
};