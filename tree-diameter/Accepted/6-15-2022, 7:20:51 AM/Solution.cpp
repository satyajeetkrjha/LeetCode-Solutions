// https://leetcode.com/problems/tree-diameter

class Solution {
public:
     vector <int> adj[10005];
    pair<int ,int> bfs(int node ,vector <int> &dist,int n){
        
        dist[node] = 0 ;
       
        queue <int> q;
        q.push(node);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i =0 ;i<adj[cur].size();i++){
              int v = adj[cur][i];
              if(dist[v] == -1){
                dist[v] = dist[cur]+1;
                q.push(v);
            }
                
          }
        }
        
        int ans = INT_MIN;
        int farthestnode=0;
        for(int i =0 ;i<=n;i++){
            if(dist[i]> ans){
                ans = dist[i];
                farthestnode = i ;
            }
        }
        return {ans,farthestnode};

    }
    
    
    int treeDiameter(vector<vector<int>>& edges) {
        int startnode =0 ;
        int n = edges.size();
        
       
        
        for(int i =0 ;i<n;i++){
            int u = edges[i][0];int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            startnode = u;
        }
        
        vector <int> dist(n+2,-1);
        
        auto firstbfsval = bfs(startnode,dist,n); 
        
     
        for(int i =0 ;i<=n;i++) dist[i] = -1;
        
        auto secondbfs =bfs(firstbfsval.second,dist,n);

        return secondbfs.first ;
        
        
        
        
        
    }
};