// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map <int ,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
      for(map<int,int>::iterator it =m.begin();it!=m.end();++it){
        if(it->second){
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