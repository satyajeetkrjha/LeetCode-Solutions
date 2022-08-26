// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string n) {
       int start = 0; 
	int end = n.size() - 1;
    while(start < end){
        if(!isalnum(n[start])){start++; }
        else if(!isalnum(n[end])){end--;}
        else if(tolower(n[start++]) != tolower(n[end--])){
            return false;
        }
    }
    return true;
    }
};