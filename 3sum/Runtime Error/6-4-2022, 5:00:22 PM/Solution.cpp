// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l=0 ;
        int r =0;

        sort(nums.begin(),nums.end());
        
        vector <vector <int> > res ;
        if(nums.size() <3){
            return res ;
        }
        
        for(int i =0 ;i< nums.size();i++){
            l = i+1;
            r = nums.size()-1;
            
            while(l<r){
               
                vector <int> temp;
                if(nums[i]+nums[l]+nums[r]== 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    int numsleft = nums[l];
                    int numsright= nums[r];
                    while(numsleft == nums[l] && l<r){
                        l++;
                    }
                    while(numsright == nums[r] && l<r){
                        r--;
                    }
                    
                }
                else if(nums[i]+nums[l]+nums[r] <0){
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r] >0){
                    r--;
                }
            }
            while(i<nums.size() && nums[i] == nums[i+1]){
                i++;
            }
                          
        }
        
        
        return res ;
        
        
    }
};