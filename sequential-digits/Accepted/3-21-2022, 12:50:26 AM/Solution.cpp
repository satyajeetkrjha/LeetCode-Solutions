// https://leetcode.com/problems/sequential-digits

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        queue <int> q;
        for(int i =1 ;i<=9 ;i++){
            q.push(i);
        }
       
        vector <int> res ;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(val >= low && val <= high){
                res.push_back(val);
            }
            if(val > high){
                break;
            }
            int lastdigit = val %10;
            if(lastdigit <9){
                q.push(val*10+(lastdigit+1));
            }
        }
        return res ;
        
        
    }
};