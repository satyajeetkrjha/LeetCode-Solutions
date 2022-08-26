// https://leetcode.com/problems/find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
       int celebritycandidate =0;
        for(int i=0;i<n;i++){
            if(knows(celebritycandidate,i)){
                celebritycandidate =i;
            }
        }
        bool flag = isCelebrity(celebritycandidate,n);
        if(flag){
            return celebritycandidate;
        }
        else 
            return -1;
    }
    bool  isCelebrity(int i,int n){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(knows(i,j) || !knows(j,i)){
                return false;
            }
        }
        return true;
    }
};