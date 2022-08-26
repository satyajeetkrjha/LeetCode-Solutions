// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <iostream>     // std::cout
#include <algorithm>    // std::max
using namespace std;
class Solution {
public:
    int max_fun(int a,int b){
        if(a>=b)
            return a;
        return b;
    }
    int lengthOfLongestSubstring(string str) {
        set <char > s;
        int left =0;
        int right =0;
        int max_length=0;
        while(right< str.size()){
            char character =str[right];
            if(s.find(character) != s.end()){
                s.insert(character);
                max_length =max_fun(max_length,s.size());
                right ++;
            }
            else {
                s.erase(character);
                left++;
            }
        }
        return max_length;
    }
};