// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
  int longestMountain(vector<int> &arr) {
    const int none = 0, up = 1, down = 2;

      int best = 0;
      int n = arr.size();
      int status =none;
      int start =-1;
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i - 1]) {
        if (status != up) status = up, start = i - 1;
      } else if (arr[i] < arr[i - 1]) {
        if (status != none) status = down, best = max(best, i - start + 1);
      } else
          status = none;
    }
    return best;
  }
};