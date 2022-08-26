// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    
    vector <int> adj[10005];
   
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       

        for(int i =0 ;i< edges.size();i++){
            int u = edges[i][0];int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         
        int dist[n+2];
        for(int i =0 ;i<n;i++){
            dist[i] = INT_MAX;
        }
        queue <int> q;
        q.push(source);
        dist[source] = 0 ;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto neigh:adj[u]){
                if(dist[neigh]> dist[u]+1){
                    dist[neigh] = dist[u]+1;
                    q.push(neigh);
                }
            }
        }
        
        return dist[destination] == INT_MAX ?  false :true ;
        
        
        
        
    }
};