// https://leetcode.com/problems/maximum-swap

#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int maxIndex =-1;
        int leftIndex =-1;
        int maxDigit =-1;
        int rightIndex =-1;
        for(int i=s.length()-1;i>=0;i--){
            // if we find a. number greater than the maxDigit we have found till now we just need to update the maxDigit and continue .We don't do anything else in this specific case
           if(s[i] >maxDigit){
               maxDigit = s[i];
               maxIndex =i;
               continue ;
           }
          if(maxDigit >s[i]){
              leftIndex = i;
              rightIndex = maxIndex;
          }  
        }
        if(leftIndex == -1){
            return  num;
        }
        swap(s[leftIndex],s[rightIndex]);
        return  stoi(s);
    }
};