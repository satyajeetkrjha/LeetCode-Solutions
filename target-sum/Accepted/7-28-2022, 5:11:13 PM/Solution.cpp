// https://leetcode.com/problems/target-sum

class Solution {
public:
    map <pair<int ,int> ,int> m ;
    vector <int> nums ;
    int n;
    int target ;
    
    int backtrack(int index ,int total){
        if(index == n){
            return total == target ? 1 :0;
        }
        auto findcomb= m.find({index,total});
        if(findcomb!=m.end()){
            return findcomb->second ;
        }
        return m[{index,total}] = 
            backtrack(index+1,total+nums[index])
              +backtrack(index+1 ,total-nums[index]);
    }
    
    
    
    int findTargetSumWays(vector<int>& nums1, int target1) {
        nums = nums1;
        target = target1 ;
        n = nums.size();
        return backtrack(0 ,0);
    }
};