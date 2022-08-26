// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = -1;
        int high = nums.size()+2;
        while(high -low >1){
            int mid =(low+high)/2;
            cout <<"nums[mid].."<< nums[mid]<< endl;
            if(nums[mid] == target){
                low = mid;
                return low ;
            }
            else{
                high = mid ;
            }
        }
        cout <<"low and high are ..."<< low << "  "<< high << endl;
        return low  ;
    }
};