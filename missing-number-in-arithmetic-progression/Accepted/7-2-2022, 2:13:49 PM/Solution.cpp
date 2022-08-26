// https://leetcode.com/problems/missing-number-in-arithmetic-progression

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        
        int n = arr.size() ;
        int low = 0 ;
        int high = n-1;
        int diff = (arr[n-1] -arr[0]) /n ;
        while(low < high){
            int mid =(low+high)/2 ;
            if(arr[mid] == arr[0]+mid*diff){
                low = mid+1;
            }
            else{
                high = mid ;
            }
        }
        return arr[0] + low*diff ;
        
    }
};