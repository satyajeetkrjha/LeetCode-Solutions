// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
    vector<int> unique;
    for (int x : nums)
      if (++cnt[x] == 1) unique.push_back(x);

    nth_element(unique.begin(), unique.begin() + k - 1, unique.end(),
                [&](int a, int b) { return cnt[a] > cnt[b]; });
    unique.erase(unique.begin() + k, unique.end());
    return unique;
    }
};