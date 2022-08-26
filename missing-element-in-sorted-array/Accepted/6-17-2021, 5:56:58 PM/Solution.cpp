// https://leetcode.com/problems/missing-element-in-sorted-array

class Solution {
public:
    //this function tells us total missing elements till that index 
    int missing(int index,vector <int> &nums){
        return nums[index] -nums[0]-index;
    }
    int missingElement(vector<int>& nums, int k) {
        
        int n= nums.size();
        if(k > missing(nums.size()-1,nums)){
            return nums[n-1]+k-missing(n-1,nums);
        }
        // we need to find that index such that missings[idx-1]<k <= missings[idx+1]
        int start =0, end =n;
        while(end -start >1){
            int mid =(start +end)/2;
            if(missing(mid,nums)  >= k){
                end =mid;
            }
            else
                start =mid;
        }
        cout<<"start is "<<start <<endl;
        
         return nums[start]+(k -missing(start,nums));
    }
};