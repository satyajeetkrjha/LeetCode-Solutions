// https://leetcode.com/problems/basic-calculator-iii

class Solution {
public:
    int calculate(string s) {
         int i = 0;
        return parseExpr(s, i);
    }
    int parseExpr(string& s, int& i) {
        vector<int> nums;
        char op = '+';
        for (; i < s.length() && op != ')'; i++) {
            if (s[i] == ' ') continue;
            int n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
            switch(op) {
                case '+' : nums.push_back(n); break;
                case '-' : nums.push_back(-n); break;
                case '*' : nums.back() *= n; break;
                case '/' : nums.back() /= n; break;
            }            
            op = s[i];
        }
        int res = 0;
        for (int n : nums) res += n;
        return res;
    }
    
    int parseNum(string& s, int& i) {
        int n = 0;
        while(i < s.length() && isdigit(s[i]))
            n = s[i++] - '0' + 10 * n;
        return n;
    }
};