// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    vector <int> visited ;
    vector <int > adj[100005];
    
    
    
    void dfs(int u){
        if(visited[u])
            return ;
        visited[u] =1 ;
        for(int i =0 ;i< adj[u].size();i++){
            int v = adj[u][i] ;
            if(!visited[v])
                dfs(v);
        }
    }
    
    
    
    
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return  -1;
        visited.resize(n,0);
        for(int i =0 ;i< connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count = 0 ;
        for(int i  = 0 ;i< n;i++){
            if(!visited[i]){
                dfs(i);
                count ++;
            }
        }
        return count -1 ;
        
    }
};