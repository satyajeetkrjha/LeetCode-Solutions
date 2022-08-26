// https://leetcode.com/problems/two-sum

class Solution {
    vector <int> a;
    int  binary_search(int x,int y,int z){
        int low=x;int high=y;int val=z;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==val){
                return mid;
            }
            else if(a[mid]<val){
               low=mid+1;
            }
            else
           high=mid-1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        a=nums;
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            int s= binary_search(i+1,nums.size()-1,diff);
           // cout<<"diff is "<<diff<<" and s is "<<s<<endl;
            if(s!=-1){
                ans.push_back(i);ans.push_back(s);
                break;
            }
            
        }
        return ans;
    }
};