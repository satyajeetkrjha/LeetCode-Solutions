// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    vector <int> adj[10005];
    vector <int> visited ,tin ,low ;
    int timer;
    
    vector <vector <int> > res ;
    void dfs (int u ,int p =-1){
        visited[u] =1 ;
        tin[u] = low[u] = timer++;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if( v == p ) continue ;
            if(visited[v]){
                low[u] = min(low[u],tin[v]);
            }
            else{
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v] > tin[u]){
                    vector <int> temp ={v,u};
                    res.push_back(temp);
                }
                
            }
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
      
        
        for(int i =0 ;i<n;i++){
            int u  = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        timer =0 ;
        visited.assign(n+1,0);
        tin.assign(n+1,-1);
        low.assign(n+1,-1);
        
        for(int i =0 ;i<n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        
    return res;
    }
};