// https://leetcode.com/problems/graph-valid-tree

class Solution {
public:
    vector <int> visited;
    vector <int> adj[100005];
    
    bool flag = false;
    void dfs(int u ,int parent){
        if(!visited[u])
            visited[u] =1 ;
        for(int i=0 ;i< adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                dfs(v,u); 
            }
            else if( visited[v] && v!=parent){
                flag = true;
                return;
            }
        }
    }
    
    
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
       visited.resize(n,0);
       for(int i =0 ;i< edges.size();i++){
           int u = edges[i][0];int v = edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       dfs(0,-1) ;// start a dfs with node 0 and set it's parent to be 1
       for(int i =0 ;i< n;i++){
           if(!visited[i])
               return false;
       } 
       
       return !flag ? true :false;
    }
};