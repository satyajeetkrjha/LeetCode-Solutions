// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
       vector <int> res(n,0);
        int left =0 ;
        int right = n-1;
        int start  = 1;
        while(left <right){
            res[left++] = start ;
            res[right--] = -start ;
            start++;
        }
        return res ;
    }
};