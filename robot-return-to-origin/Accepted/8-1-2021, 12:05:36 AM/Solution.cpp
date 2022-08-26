// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int x =0 ;int y =0;
         int sz = moves.size();
        for(int i =0 ;i<sz;i++){
            if(moves[i] == 'U'){
                x--;
            }
            else if (moves[i] == 'D'){
                x++;
            }
            else if (moves[i] == 'L'){
                y--;
            }
            else if (moves[i] == 'R'){
                y++;
            }
        }
        if(x == 0 && y==0)
            return true;
        return false;
    }
};