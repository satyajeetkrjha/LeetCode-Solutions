// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    vector <pair <int ,int> > adj[1000005];
    int count =0;
    void dfs(int u,int parent){
        for(auto[v,cost]:adj[u]){
            if(v == parent) continue;
            else{
                if(cost == 1) count++;
                dfs(v,u);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i =0 ;i< connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back({v,1}); 
            adj[v].push_back({u,0});
        }
        dfs(0,0);
        return count ;
        
    }
};