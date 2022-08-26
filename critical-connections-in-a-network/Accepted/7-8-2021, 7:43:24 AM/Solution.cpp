// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    vector <int> disc;
    vector <int> low ;
    vector <int> parent;
    vector < vector <int > > ans ;
    vector < vector <int> > adj;
    
    int time =0;
    void dfs(int u){
        disc[u] = low[u]=time++;
        for(int i =0;i<adj[u].size();i++){
            int v= adj[u][i];
            if(disc[v]== -1){
                parent[v] =u ;
                dfs(v);
                if(low [v] >disc[u]){
                    ans.push_back({v,u});
                }
                low[u] = min(low[u],low[v]);
            }
            else if ( v!= parent [u]){
                low[u] = min(low[u],low[v]);
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low.resize(n,-1);
        disc.resize(n,-1);
        parent.resize(n,-1);
        
        adj.resize(n);
        for(int i =0;i<connections.size();i++){
            vector <int> v = connections[i];
            int a = v[0];int b = v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i =0;i<n;i++){
            if(disc[i] == -1){
                dfs(i);
            }
        }
        return ans ;
    }
};