// https://leetcode.com/problems/fixed-point

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int ans =-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == i){
                ans =i;
                break;
            }
        }
        return ans;
    }
};