// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
       int n= nums.size();
        int min_jumps[n+1];
       min_jumps[0]=0;
       if(n ==0 || nums[0]== 0)
           return 0;
        for(int i=1;i<n;i++){
             min_jumps[i]=INT_MAX;
            for(int j=0;j<i;j++){
               if(nums[j]+j>=i && min_jumps[j]!=INT_MAX){
                   // cout<<"min_jumps[j]+1 is "<<" "<<min_jumps[j]+1<<endl;
                   // cout<<"min_jumps[i] "<<min_jumps[i]<<endl;
                   min_jumps[i]=min_jumps[j]+1;
                   break;
                  // cout<<"i "<<i<<" "<<min_jumps[i]<<endl;
               } 
            }
        }
        return min_jumps[n-1];
    }
};