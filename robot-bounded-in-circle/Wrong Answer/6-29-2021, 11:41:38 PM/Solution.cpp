// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int directions[][4] ={{0,1},{1,0},{0,-1},{-1,0}};
        int x =0;
        int y =0;
        int dir =0;
        for(int i =0;i<instructions.size();i++){
            char c = instructions[i];
            if(c == 'L'){
                dir = (dir+3)%4;
            }
            if(c == 'R'){
                dir = (dir+1)%4;
            }
            else {
                x = x+ directions[dir][0];
                y= y+directions [dir][1];
            }
        }
        return ( x==0 && y==0 ) || (dir!=0);
    }
};