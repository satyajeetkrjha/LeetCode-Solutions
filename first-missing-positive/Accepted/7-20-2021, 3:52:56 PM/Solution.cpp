// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        bool onefound =false ;
        for(int i =0;i<nums.size();i++){
            if(nums[i] ==1){
                onefound =true;
                break;
            }
        }
        if(!onefound) return 1;
        
        int n = nums.size();
        
        for(int i =0;i<nums.size();i++){
             if(nums[i] <=0 || nums[i] >n){
                  nums[i] =1;
             }
        }
        
        // for(int i =0;i<n;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i =0 ;i<n;i++){
            int val = abs(nums[i]);
            if( val == n){
                nums[0] = -1 *abs(nums[0]);
            }
            else {
                nums[val] = -1 *abs(nums[val]);
            }
        }
        // cout<<"after marking "<<endl;
        // for(int i =0 ;i<n;i++){
        //     cout<<nums[i]<< " ";
        // }
        // cout<<endl;
        
        for(int i =1 ;i<n;i++){
            if(nums[i] >0){
                return i;
            }
        }
        if(nums[0] >0){
            return n;
        }
        return n+1;
        
    }
};