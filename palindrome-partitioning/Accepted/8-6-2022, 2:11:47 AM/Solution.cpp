// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
     vector <vector <string> > res ;
    bool isPalindrome(string s ,int i ,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    vector<string> temp ; // temp
    void backtrack(string &s,int i){ 
        if(i>=s.size()){
            res.push_back(temp);
            return ;
        }
        for(int j = i ;j <s.size();j++){
            if(isPalindrome(s,i,j)){
                string substring = s.substr(i,j-i+1);
                temp.push_back(substring);
                backtrack(s,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res ;
    }
};