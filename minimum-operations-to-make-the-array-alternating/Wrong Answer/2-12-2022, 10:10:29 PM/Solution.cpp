// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        vector <int> temp ;
        temp = nums;
        int ans =0 ;
        for(int j =0 ;j< nums.size();j++){ 
             if(j+1 <nums.size() && j+2 <nums.size()){
                    if(nums[j] ==nums[j+2] && nums[j+2]!=nums[j+1]){
                      continue;
                }
                if(nums[j]!=nums[j+2]){
                    
                    if(nums[j+2]>nums[j]){
                     
                        nums[j+2]= nums[j];
                    }
                    else{
                   
                        nums[j]= nums[j+2];
                    }
                    
                }
                if(nums[j+1] == nums[j+2]){
               
                    nums[j+1]=nums[j+1]+1;
            
                }    
              }    
            }
        
        /*
        for(auto it :nums){
            cout <<it << " ";
        }
        cout << endl;
        */
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                ans ++;
            }
        }
        
        
        
        
        return ans;
        
    }
};