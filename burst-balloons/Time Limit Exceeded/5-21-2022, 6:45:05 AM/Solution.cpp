// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size()+2;
        
        vector <int> newNums(n);
        newNums[0] =1 ;
        newNums[n-1]=1;
        for(int i = 1;i<=n-2;i++){
            newNums[i] = nums[i-1];
        }
        
        /*
        for(auto &it:newNums){
            cout <<it << "  ";
        }
        cout << endl;
      */
        
        cout << endl;
        vector <vector <int>> memo;
        memo.resize(n,vector<int>(n,0));
        
        return dp(memo,newNums,1,n-2);
    }
    
    
    
    int dp(vector <vector<int>>memo,vector <int> nums,int left,int right){
        // base case 
        if(right < left){
            return 0;
        }
        
        if(memo[left][right]>0) 
            return memo[left][right];
        
        int res =0;
        for(int i =left ;i<=right;i++){
            int gain = nums[i]*nums[right+1]*nums[left-1];
            int remaining = dp(memo,nums,left,i-1)+
                dp(memo,nums,i+1,right);
            res = max(res ,remaining+gain);
        }
        memo[left][right] = res;
        return res;        
    }
    
};