// https://leetcode.com/problems/graph-valid-tree

class Solution {
private:
  vector <int> adj[2005];  
  bool visited[2005];
    
public:
    void dfs (int u){
        if(!visited[u]){
            visited[u]=true;
        }
        for(int i = 0;i<adj[u].size();i++){
            int v= adj[u][i];
            if(!visited[v]){
                 dfs(v);
            }
           
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++){
            vector <int> v = edges[i];
            cout<<"v.size() is "<<v.size()<<endl;
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(0);
        for(int i=0;i<n;i++){
            if(!visited[i])
                return false ;
        }
        if((n-1)!= edges.size()){
            return false ;
        }
        return true ;
    }
};