// https://leetcode.com/problems/3sum

#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(),nums.begin()+n);
        vector <vector <int> > v;
        for(int i=0;i<n-1;i++){
            int x = nums[i];
            int l =i+1;
            int r=n-1;
            vector <int> v1;
            while(l<r){
                if (x+nums[l]+nums[r]==0){
                    cout<<"x is at index "<<i<<" "<<x<<endl;
                    cout<<"nums[l] is at index "<<l<<" "<<nums[l]<<endl;
                    cout<<"nums[r] is at index "<<r<<" "<<nums[r]<<endl;
                    cout<<endl;
                    v1.push_back(x);
                    v1.push_back(nums[l]);
                    v1.push_back(nums[r]);
                    l++;
                    r--;
                    v.push_back(v1);
                    v1.clear();
                    int leftValue =nums[l];
                    int rightValue =nums[r];
                    while(l <n && nums[l] ==leftValue){
                        l++;
                    }
                    while(r >l && rightValue ==nums[r]){
                        r--;
                    }
                }
                else if (x+nums[l]+nums[r]<0){
                    l++;
                }
                else {
                    r--;
                }
            }
            
            v1.clear();
        }
        return v;
    } 
};