// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low =0;
        int high =nums.size();
        int val1=-1;
        int val2=-1;
        if(nums.size() ==0){
            vector <int> v;
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid] ==target){
              val1=mid;   
                break;
            }
            else if(target >nums[mid]){
                low =mid+1;
            }
            else{
                high =mid-1;
            }
        }
        vector <int> v;
        if(val1==-1){
            v.push_back(val1);
            v.push_back(val2);
            return v;
        }
        else {
            for(int i =val1;i<nums.size();i++){
                if(nums[i] == target){
                    i++;
                    val2=i;
                }
            }
            v.push_back(val1);
            v.push_back(val2);
            return v;
        }
        
    }
};