// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map <int ,int > m; // sum and index
        m[0] = -1;
        int sum =0;
        for(int i =0;i< nums.size();i++){
            sum = sum +nums[i];
            if( k!= 0){
                sum = sum %k;
            }
            cout<<"sum val is "<<sum<<endl;
            cout <<"m[sum] is "<<m.count(sum)<<endl;
            if(m.count(sum)>0){
                if(i-m[sum] >=2){
                    return true;
                }
            }
            
            m[sum] =i;
            cout<<"m[sum] after modification is "<<m[sum]<<endl;
        }
        return false;
    }
};