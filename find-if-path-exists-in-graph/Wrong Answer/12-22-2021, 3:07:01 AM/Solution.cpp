// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
          
        vector <vector <int> > adj(n+2);
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int dist[n+2];
        for(int i =0 ;i<n+2;i++){
            dist[i] = -1;
        }
        dist[start] =0 ;
        queue <int> q;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i =0 ;i<adj[u].size();i++){
                int v = adj[u][i];
                if(dist[v] == -1){
                    dist[v] = dist[u]+1;
                }
            }
        }
        return dist[end] == -1 ? false :true ;
        
        
        
    }
};