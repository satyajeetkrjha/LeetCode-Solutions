// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        queue <int> q ;
        for(int i =1 ;i<=9 ;i++){
            q.push(i);
        }
        
        vector<int> res ;
        for(int i =1 ;i<n;i++){ // n levels 
             int sz = q.size();
             for(int j = 0 ;j< sz;j++){
                 int num = q.front();
                 q.pop();
                 int lastdigit = num %10 ;
                 if(lastdigit+k <=9){  
                     q.push(num *10 + (lastdigit+k));
                 }
                 if(lastdigit - k >=0 && k!=0){
                     q.push(num *10 +(lastdigit-k));
                 }
             }  
        }
        
        if(n == 1 ){
            res.push_back(0);
        }
        while(!q.empty()){
            int num = q.front();
            q.pop();
            res.push_back(num);
        }
        return res ;
        
        
        
    }
};