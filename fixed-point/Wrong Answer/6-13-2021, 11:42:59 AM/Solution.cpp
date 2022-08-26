// https://leetcode.com/problems/fixed-point

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
       int ans =-1;
        int low =0;
        int high = arr.size()-1;
        while(low <high){
            int mid =(low+high)/2;
            
            if (arr[mid]> mid){
                high =mid-1;
            }
            
            else if (arr[mid]<mid){
                low =mid+1;
            }
            
            else if(arr[mid] == mid){
                ans =mid;
                high =mid-1;        
                    
            }
           
        }
    return ans ;
    }
};