// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    void flood_fill(vector<vector<int>>& grid ,int i ,int j,  vector <pair <int,int>> &r){
        if( i <0 || j < 0 || i >= grid.size() || j>=grid[i].size() || grid[i][j] ==0)
            return ;
        grid[i][j] =0;
        r.push_back(make_pair(i,j));
        flood_fill(grid,i+1,j,r);
        flood_fill(grid,i-1,j,r);
        flood_fill(grid,i,j+1,r);
        flood_fill(grid,i,j-1,r);
        return ;
        
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector <pair <int,int>> first ;
        vector <pair <int,int>> second ;
        int n = grid.size();
        int m = grid[0].size();
       
        
        int count =1;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    if( count ==1){
                        flood_fill(grid,i,j,first);
                    }
                    if( count ==2){
                        flood_fill(grid,i,j,second);
                    }
                    count++;
                }
            }
        }
        int ans = INT_MAX;
        for(int i =0;i<first.size();i++){
            for(int j =0;j<second.size();j++){
                auto[a,b] = first[i];
                auto[c,d] = second[j];
                // cout<<"values are "<< a<< " "<<b<< " "<<c <<" "<<d<<endl;
                ans = min (ans ,abs(a-c)+abs(b-d)-1);
            }
        }
        return ans ;
        
        
    }
};