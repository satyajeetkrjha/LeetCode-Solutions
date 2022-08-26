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
                    cout<<"i is "<<i<<endl;
                    cout<<" l is "<<l<<endl;
                    cout<<"r is "<<r<<endl;
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
                        cout<<"l moved to"<<l<<endl;
                    
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
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
            
            //v1.clear();
        }
        return v;
    } 
};