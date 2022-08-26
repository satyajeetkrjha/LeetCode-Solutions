// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

#include <iostream>
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n %k !=0)
            return false;
        map <int ,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
      for(map<int,int>::iterator it =m.begin();it!=m.end();++it){
        // cout<<"it->first "<<it->first<<endl;
        // cout <<"it->second "<<it->second <<endl;  
        while(it->second>0){
            // cout<<"val inside is "<<it->second<<endl;
            for(int i=it->first;i<it->first+k;i++){
                m[i]--;
                if(m[i]<0)
                    return false;
            }
        }   
      }
        return true;
    }
};