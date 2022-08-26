// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> vec = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void backtrack(vector<string> &res,string &temp,string digits,vector<string>vec,int start){
        if(temp.size() == digits.size()){
            res.push_back(temp);
            return;
        }
        int index = digits[start]-'0'; // this will give 2 3 4 ..... 
        for(int i = 0 ;i<vec[index].size();i++){
            temp.push_back(vec[index][i]);
            backtrack(res,temp,digits,vec,start+1);
            temp.pop_back();
        }
    
    }
    
    
    
    vector<string> letterCombinations(string digits) {
        vector <string> res;
        string temp;
        if(digits.size() == 0)
            return res ;
        backtrack(res,temp,digits,vec,0);
        return res ;
        
    }
};