// https://leetcode.com/problems/fixed-point

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
       int start =-1;
        int end =arr.size()-1;
       while(end -start >1){
           int mid =(start+end)/2;
           ((arr[mid]>=mid)?end:start) = mid;
           
         }
        return ((end<(arr.size()-1) && arr[end] == end))?end:-1;
    };   
       
};