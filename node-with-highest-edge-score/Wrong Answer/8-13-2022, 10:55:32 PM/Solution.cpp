// https://leetcode.com/problems/node-with-highest-edge-score


class Solution {
public:
    int scores[100005];
    vector <int> adj[100005];
    bool visited[100005];
    
    void dfs(int u ){
        if(!visited[u])
            visited[u] = true;
        for(int i =0;i< adj[u].size();i++){
              int v = adj[u][i];
             if(visited[v]) continue;
              scores[v]+=u;
              dfs(v);  
        }
  }
    int edgeScore(vector<int>& edges) {
        memset(visited,false,sizeof(visited));
        int n = edges.size();
        for(int i = 0 ;i<n;i++){
            int node = edges[i];
            adj[i].push_back(node);
        }
    
        for(int i =0 ;i<n;i++){
                dfs(i);
        }
        
        int ans = -1 ;
        int node;
        for(int i =0 ;i<=n;i++){
            if(scores[i]>=ans){
                ans = scores[i];
                node = i;
            }
        }
        
        
       
        
        return node ;
    }
};