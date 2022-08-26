// https://leetcode.com/problems/possible-bipartition

class Solution {
    
public:
    vector <int> adj[2005];
    bool bfs (vector <int> &color,int u){
        queue <int> q ;
        q.push(u);
        color[u] = 0;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto &neigh :adj[cur]){
                if(color[neigh] == color[cur]){
                    return false;
                }
                else {
                    q.push(neigh);
                    color[neigh] = 1 - color[cur];
                }
            }
        }
        return true ;
    }
    
    

    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        int sz = dislikes.size();
        
        for(int i =0 ;i< sz;i++){
            int u = dislikes[i][0] ;int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector <int> color(n+1,-1);
        
        bool isbipartite= true;
        for(int i =0 ;i< n;i++){
            if(color[i] == -1){
                if(bfs(color,i) == false){
                    isbipartite = false;
                    break;
                }
            }
        }
        
        return isbipartite ;
        
        
        
        
    }
};