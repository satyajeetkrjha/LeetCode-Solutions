// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1 ;i>=0 ;i--){
            if(digits[i] == 9){
                digits[i] =0;
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        
        // we are here because input sample had only 9999
        // now our digit looks like 0000
        // so make 0'th index 1 and it becomes 1000
        // now push one more zero at last to make it 10000
        digits[0] =1 ;
        digits.push_back(0);
        return digits ;
        
    }
};