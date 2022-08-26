// https://leetcode.com/problems/self-dividing-numbers


#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    bool selfdividingfun(int n){
         // mathenatical way 
        int val =n;
        while(n!=0){
            int r = n %10;
            if(r == 0 || val % r !=0){
                return false;
            }
            n = n/10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> res ;
        for(int i = left ;i<=right ;i++){
            if(selfdividingfun(i)){
                res.push_back(i);
            }
        }
       // cout <<selfdividingfun(21)<<endl;
        return res;
    }
};