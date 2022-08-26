// https://leetcode.com/problems/minimum-knight-moves

class Solution {
public:
    int minKnightMoves(int x, int y) {
        int dx[8] ={-2,-2,2,2,-1,-1,1,1};
        int dy[8] ={-1,1,-1,1,-2,2,2,-2};
        queue < pair <int,int> > q;
        q.push(make_pair(0,0));
        int steps =0;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0;i<sz;i++){
                pair <int ,int> cur =q.front();
                q.pop();
                if(cur.first == x && cur.second == y){
                    return steps ;
                }
                for(int i =0;i<8;i++){
                    int nr = cur.first+dx[i];
                    int nc = cur.second +dy[i];
                    q.push(make_pair(nr,nc));
                }
            }
            steps ++;
        }
        return steps ;
            
    }
};