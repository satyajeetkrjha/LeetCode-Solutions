// https://leetcode.com/problems/find-the-difference

#include <iostream>

class Solution {
public:
    char findTheDifference(string s, string t) {
      s.append(t);
        cout<<"string is "<<s<<endl;
      char sum=s[0];
        for(int i=1;i<s.length();i++){
          sum =sum^s[i];
            cout<<"sum is "<<sum<<endl;
              
        }
        return sum;
        
        
    }
};