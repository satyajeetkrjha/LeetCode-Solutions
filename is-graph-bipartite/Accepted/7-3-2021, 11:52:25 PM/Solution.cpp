// https://leetcode.com/problems/is-graph-bipartite


// https://leetcode.com/problems/is-graph-bipartite/discuss/1289575/C%2B%2B-super-simple-solution-using-BFS
class Solution {
public:
     
  
    bool dfs( int u ,vector<vector<int>>& graph,vector <int> &color){
       queue <int> q;
        q.push(u);
        color[u] =1;
        while(!q.empty()){
           int node = q.front();
            q.pop();
              for(auto it:graph[node]){
                if( color[it] == -1){
                    color [it] = 1-color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
            
        }
        return true;
        
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       
        int n = graph.size();
        vector <int> color(n+1,-1);
        for(int i =0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};