// https://leetcode.com/problems/3sum

class Solution {
public:
    vector <vector <int> > res ;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l ;
        int r ;
        sort(nums.begin(),nums.end());
        // i is fixed and l and r are then moved 
        for(int i =0 ;i<nums.size();i++){
            l = i+1;
            r = nums.size() -1 ;
            while(l <r){
                if(nums[i]+nums[l]+nums[r] == 0){
                    vector <int> temp ;
                    temp.push_back(nums[i]);
                     temp.push_back(nums[l]);
                     temp.push_back(nums[r]);
                    
                    res.push_back(temp);
                    // what if nums[l] and nums[l+1] are same but we don't want them
                    int numsleft = nums[l];
                    int numsright = nums[r];
                    while(numsleft == nums[l]){
                        l++;
                    }
                    while(numsright == nums[r]){
                        r--;
                    }
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    r--;
                }
            }
            while(i+1 <nums.size() && nums[i] == nums[i+1]){
                i++;
            }
        }
        return res ;
    }
};