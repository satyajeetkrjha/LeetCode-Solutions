// https://leetcode.com/problems/rotting-oranges

#include <iostream>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();// number of rows
        int m =grid[0].size();//number of columns
        queue <pair<int,int>>q; // a queue of all rotten coordinates
        
        int freshOranges =0; 
        int rottenOranges=0;
        
        const int  ROTTEN=2;
        const int  FRESH_ORANGE=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==ROTTEN){
                    rottenOranges++;
                    pair <int,int> coordinate=make_pair(i,j);
                    q.push(coordinate);
                }
               else if(grid[i][j]==FRESH_ORANGE){
                    freshOranges++;
                }
            }
        }
        // look at second testcase 
        if(freshOranges==0){
            return 0;
        }
        if(rottenOranges==0){ // you don't have any rootten orange to infect
            return -1;
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int time =0;
        while(q.size()>0 && freshOranges>0){ // we have rootten ornages to start the bfs and ample freshOranges to inect
            int numOfRottenOranges= q.size();// total number of corrdinates where we have rotten oranges now
            for(int i=0;i<numOfRottenOranges;i++){
                // we will infect all fresh oranges with all these coordinates that we have now
                pair<int,int> coordinate =q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x =dx[i]+coordinate.first;
                    int y=dy[i]+coordinate.second;
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==FRESH_ORANGE){ // valid coordinate check and fresh orange check
                        freshOranges--; // decrease the count of fresh orange by 1 because we just infected it 
                        grid[x][y]=ROTTEN; // make it rotten and now push it to queue
                        pair<int,int> rooten_coordinate =make_pair(x,y);
                        q.push(rooten_coordinate);
                        
                    }
                }
            }
            time++;
            
        }
        if(freshOranges==0)
        return time;
        else
            return -1;
        
    }
};