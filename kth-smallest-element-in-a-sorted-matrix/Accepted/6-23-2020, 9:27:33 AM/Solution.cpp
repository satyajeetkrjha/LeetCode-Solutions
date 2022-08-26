// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

#include <algorithm>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int sz= matrix.size();
        int low =matrix[0][0];
        int high =matrix[sz-1][sz-1];
       
        while(low<high){
            int mid =(low+high)/2;
             int count =0;
            for(int i=0;i<sz;i++){
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count <k){
                low =mid+1;
            }
            else
                high =mid;
            
        }
        return low ;
    }
};