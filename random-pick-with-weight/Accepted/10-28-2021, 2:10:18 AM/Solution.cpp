// https://leetcode.com/problems/random-pick-with-weight

#define pb push_back 
class Solution {
public:
    vector <int> v;
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for(int i =1;i<w.size();i++){
            v.push_back(v.back()+w[i]);
        }
        
    }
    
    int pickIndex() {
      int rand_weight = rand()%(v.back());
       return upper_bound(v.begin(),v.end(),rand_weight) - v.begin(); 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */