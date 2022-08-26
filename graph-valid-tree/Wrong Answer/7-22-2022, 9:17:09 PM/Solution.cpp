// https://leetcode.com/problems/graph-valid-tree

class Solution {
public:
    int visited[2005];
    bool cyclefound = false;
     vector <int> adj[2005];
    void dfs(int u ,int parent){
        if(!visited[u])
            visited[u] = 1 ;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                dfs(v,u);
            }
            else if (visited[v] && v!= parent){
                cyclefound = true ;
                return ;
            }
        }
    }
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
     
     
      
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0] ;int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i =0 ;i<n;i++) 
            visited[i] =0;
        
        dfs(0,-1);
        return !cyclefound ;
        
        
        
        
        
    }
};