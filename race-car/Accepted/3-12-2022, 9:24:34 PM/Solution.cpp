// https://leetcode.com/problems/race-car

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0,0,1}) ;// moves ,position and speed
      
        while(!q.empty()){
            auto vec  = q.front();
            q.pop();
            
            int moves = vec[0];
            int pos = vec[1];
            int speed = vec[2];
            
            if(pos == target) return moves ;
            
            if(abs(pos) >2*target) continue ;
            
            q.push({moves+1,pos+speed,speed*2});
           
            if((pos+speed > target && speed >0 )|| (pos +speed <target && speed <0)){
                q.push({
                    moves+1,
                    pos,
                    speed >0 ?-1:1
                    });
            }  
        }
        return 0;
            
            
        
    }
};