// https://leetcode.com/problems/cinema-seat-allocation

class Solution {
public:
    map <int ,set <int> > m;
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    
        for(auto seats :reservedSeats){
            int x = seats[0];
            int y = seats[1];
            m[x].insert(y);  
        }
        int res =0;
        for(int i =1 ;i<=n;i++){
            auto s = m[i] ; 
            bool flag = false;
           
            if(!s.count(2) && !s.count(3) && !s.count(4) && !s.count(5)){
                res ++;
                flag = true;
            }
              if(!s.count(6) && !s.count(7) && !s.count(8) && !s.count(9)){
                res ++;
                flag = true;
            }
            if(!flag && !s.count(4) && !s.count(5) && !s.count(6) && !s.count(7)){
                res ++;
            }
           
            
        }
        return res ;
        
        
    }
};