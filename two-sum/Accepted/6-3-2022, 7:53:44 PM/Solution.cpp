// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector <int> v ;
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int ,int> m;
        vector <int> v;
        for(int i =0 ;i< nums.size();i++){
            int x = nums[i];
            if(m.find(target-x)!=m.end()){
               // cout <<"taget-x is "<< target-x <<endl;
                //cout <<"m[target-x] is "<< m[target-x]<< endl;
                v.push_back(i);
                v.push_back(m[target-x]);
                break;
            }
            m[x] =i;
        }
        return v ;
    }
};