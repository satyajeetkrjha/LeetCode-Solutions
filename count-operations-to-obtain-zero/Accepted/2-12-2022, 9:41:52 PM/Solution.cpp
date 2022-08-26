// https://leetcode.com/problems/count-operations-to-obtain-zero

class Solution {
public:
    
    int recur(int num1,int num2){
        if(num1%num2 ==0){ // 18  6
            return num1/num2;
        }
        
        return num1/num2 +recur(num2,num1%num2);
        
    }
    
    int countOperations(int num1, int num2) {
       if(num1 ==0 || num2 ==0)
           return 0;
        
       if(num1 <num2){
           swap(num1,num2);
       }
        return recur(num1,num2);
    }
};