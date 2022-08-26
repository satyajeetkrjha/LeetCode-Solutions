// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n = nums.size();
        map <int,int> m;
        int sum =0;
        int ans=0;
        int diff =0;
        for(int i=0;i<n;i++){
          sum+= nums[i] ==1 ?1:-1;
            cout<<"sum is "<<sum<<endl;
          if(m.find(sum)==m.end() && sum!=0){
              m[sum]=i;
          }
            else if(m.find(sum)!=m.end() && sum!=0) {
             diff =i-m[sum]+1;
              ans =max(ans,diff);
          }
            else {
                diff =i+1;
                ans =max(ans,diff);
            }
            
            
            
           
        }
        return ans;
        
    }
};