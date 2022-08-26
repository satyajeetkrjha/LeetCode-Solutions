// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        int major_element=nums[0];
        int count =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==major_element){
                     count++;
                major_element =nums[i];
            }
            else{
                count--;
                if(count ==0){
                      major_element=nums[i];
                    count=1;
                }
              
            }
        }
        return major_element;
        
    }
};