// https://leetcode.com/problems/missing-number-in-arithmetic-progression

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int sum = (n+1)*(arr[0]+ arr[n-1])/2 ;
        int arrsum =0 ;
        for(int i =0 ;i< n;i++){
            arrsum += arr[i];
        }
        return sum - arrsum ;
        
    }
};