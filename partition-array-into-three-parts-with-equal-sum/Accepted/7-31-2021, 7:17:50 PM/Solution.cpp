// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
       int sum = 0;
       for(int i = 0 ;i<arr.size();i++){
           sum += arr[i];
       } 
        if(sum%3!=0){
            return false;
        }
        int partialsum =0 ;
        int count =0 ;
        for(int i =0 ;i<arr.size();i++){
            partialsum +=arr[i];
            if(partialsum == sum/3){
                partialsum =0;
                count ++;
                if(count == 3){
                    return true;
                }
            }
        }
        return false;
        
        
        
        
    }
};