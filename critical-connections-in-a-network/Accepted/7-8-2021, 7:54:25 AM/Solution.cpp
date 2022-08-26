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
        // cout <<"dfs starts at node "<<u<<endl;
        for(int i =0;i<adj[u].size();i++){
            int v= adj[u][i];
            // cout<<" neighbour of node "<<u<< " is "<<v<<endl;
            if(disc[v]== -1){
                parent[v] =u ;
                dfs(v);
                
                // cout<<"v is "<<v << " and low["<<v<<" ] is "<<low[v]<<endl;
                // cout<<"u is "<<u << " and disc [" <<u<<" ] is "<<disc[u]<<endl;
                if(low [v] >disc[u]){
                    // cout<<"Brifge code"<<endl;
                    ans.push_back({v,u});
                      // cout<<"Brifge code over"<<endl;
                }
                low[u] = min(low[u],low[v]);
            }
            else if ( v!= parent [u]){
                // cout<<"Back edge found "<<endl;
                // cout<<"u is "<<u << " and low["<<u<<" ] is "<<low[u]<<endl;
                  // cout<<"v is "<<v << " and low["<<v<<" ] is "<<low[v]<<endl;
                low[u] = min(low[u],low[v]);
                // cout<<"Updated low  for u "<<u << " is "<<low[u]<<endl;
                // cout<<"Back edge over"<<endl;
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