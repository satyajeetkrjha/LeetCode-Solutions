// https://leetcode.com/problems/delete-and-earn

typedef long long int ll;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int count[10001]={0};
        for(int i =0 ;i<n;i++){
            count[nums[i]]++;
        }
        ll avoid = 0;
        ll usingval = 0;
        ll prev = -1;
        for(int i =0 ;i<10001;i++){
            int m = max(usingval ,avoid);
            if(i-1!=prev){
                usingval = i *count[i]+m;
                avoid = m;
            }
            else{
                usingval =i*count[i]+avoid;
                avoid =m;
            }
            prev = i;
        }
        return max(avoid ,usingval);
        
        
        
        
        
        
    }
};