// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    int floormod(int a ,int b){
        return ((a%b)+b)%b;
    }
    vector<vector<int>> generateMatrix(int n) {
       int row =0 ;
       int col =0;
       int d = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cnt =1;
        vector <vector <int> > res(n,vector <int>(n));
        while(cnt <= n*n){
            res[row][col] = cnt++;
            int r = floormod(row +dir[d][0],n);
            int c = floormod(col+ dir[d][1],n);
            cout <<"r and c are "<< r << " "<<c<<endl;
            if(res[r][c] != 0){
                d = (d+1)%4;
            }
            cout <<"d is "<<d <<endl;
            row = row + dir[d][0];
            col = col + dir[d][1];
        }
        return res ;
    }
};