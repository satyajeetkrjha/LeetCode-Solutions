// https://leetcode.com/problems/replace-elements-in-an-array

class Solution {
public:
    /*
     Look ,what we basically do here is that we first note down the index of elements in nums and we do this in map .Next as we iterate over operatyions ,we chexck where that specific element which is nothing but oprations[i][0] exists and we replace that element in nums with the new given elememnt .
     but ,hey we also need to trace the index of the newly added or say instered element so just update that in our map after we used that element to replace .
     
    */
    
    
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
      // our map will store the element and the index of that element in nums
        map <int ,int> m ;
        for(int i = 0 ;i<nums.size();i++){
            int elem = nums[i];
            m[elem] = i ;
        }
        
        for(int i =0 ;i<operations.size();i++){
            int x = operations[i][0];
            int y = operations[i][1];
            int temp = m[x] ; // store index 
            nums[m[x]] = y; // replace in array
            m[y]= temp;            // change the index
        }
        return nums ;
    }
};