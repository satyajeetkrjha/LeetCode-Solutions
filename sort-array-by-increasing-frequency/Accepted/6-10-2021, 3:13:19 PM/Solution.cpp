// https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> cnt;
    for(int n: nums) ++cnt[n];
    auto cmp = [&](int a, int b) {
       if( cnt[a] == cnt[b]){
            if(a>b){ // decreasing
                return true;
            }
           else
            return false;
        }
        else {
            if(cnt[a]<cnt[b]){ // incrasing
                return true;
            }
            else
            return false;
        }
    };
    sort(nums.begin(), nums.end(), cmp);
    return nums;
  }
};