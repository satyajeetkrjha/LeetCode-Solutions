// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    
    
    bool bfs(vector<vector<int>>& graph ,vector<int> &color ,int u){
        
        color[u] = 0 ;// red
        queue <int> q ;
        q.push(u);
        while(!q.empty()){
          auto cur = q.front();
          q.pop();
          for(auto &neigh: graph[cur]){
              if(color[neigh] == -1){
                  color[neigh] = 1 - color[cur];
                  q.push(neigh);
              }
              else if(color[neigh] == color[cur]){
                  return false ;
              }
            }  
        }
        return true;
    }
    
    
    
    
    bool isBipartite(vector<vector<int>>& graph) {
      
        int n = graph.size();
        vector <int> color(n,-1) ;
      
        bool isbipartite = true;
        for(int i =0 ;i<n;i++){
            if(color[i] == -1){
                if(bfs(graph,color,i)) // returns true means bipratite
                    continue;
                else{
                    isbipartite = false;
                    break;
                }
            }
        }
        
        return isbipartite ;
        
        
        
        
    }
};