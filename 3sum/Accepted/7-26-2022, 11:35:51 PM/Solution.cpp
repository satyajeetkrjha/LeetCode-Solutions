// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; // to avoid duplicates
        vector <vector <int> >  res ;
        int i = 0 ;
        int n = nums.size();
        int l ,r;
        while(i <nums.size()){
             l = i+1 ;
             r = n-1;
            while( l<r){
                if(nums[i]+nums[l]+nums[r] == 0){
                    vector <int> temp ;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    int numsleft = nums[l];
                    int numsright = nums[r];
                    while(nums[l] == numsleft && l<r){
                        l ++;
                    }
                    while(numsright  == nums[r] && l<r){
                        r -- ;
                    }
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l ++;
                }
                else{
                    r --;
                }
            }
            int numberati = nums[i];
            while(i+1<nums.size() && nums[i] == nums[i+1]){
                i ++;
            }
            i++;
        }
        return res ;
        
    }
};