// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    vector <int> adj[2005];
    bool visited[20005];
    
    
    void dfs(int u){
        if(!visited[u])
            visited[u] = 1 ;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v])
                dfs(v);
        }
    }
    
    
    
    int countComponents(int n, vector<vector<int>>& edges) {
       for(int i =0 ;i<edges.size();i++){
           int u = edges[i][0];int v = edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
        for(int i =0 ;i<n ;i++) visited[i] = 0;
        
        int count =0 ;
        for(int i =0 ;i<n;i++){
            if(visited[i] == 0){
                count++;
                dfs(i);
            }
        }
        return count ;
    }
};