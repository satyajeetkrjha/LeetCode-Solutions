// https://leetcode.com/problems/sign-of-the-product-of-an-array


// If there is a zero in the vector it simply means that the product of all the numbers is going to be zero
// If there are even number of negative numbers then again total product is positive else total product is negative 

class Solution {
public:
    int count  =0 ;
    int arraySign(vector<int>& nums) {
        for(int i =0 ;i<nums.size();i++){
            if(nums[i] ==0 ){
                return 0;
            }
            if(nums[i]<0){
                count++;
            }
        }
        if(count %2 ==0){
            return 1;
        }
        return -1;
    }
};