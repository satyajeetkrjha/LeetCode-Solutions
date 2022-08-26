// https://leetcode.com/problems/target-sum

class Solution {
public:
    int target;
    int n ;
    vector<int> nums ;
    int dp[25][100005];
    int backtrack(int index ,int total){
        if (index == n){
            return total == target ? 1 : 0 ;
        }
      
        return 
            backtrack(index+1,total+nums[index])+backtrack(index+1,total-nums[index]);

            
    }
    int findTargetSumWays(vector<int>& nums1, int target1) {
        target = target1 ;
        nums = nums1 ;
        n = nums.size();
        cout <<"n is "<< n << " "<< target << endl;
        for(auto &it:nums){
            cout << it << " ";
        }
        cout << endl;
        int total =0 ;
        for(int i =0 ;i<nums.size();i++){
            total +=  nums[i];
        }
       memset(dp,sizeof(dp),0);
        return backtrack(0,0);
        
    }
};