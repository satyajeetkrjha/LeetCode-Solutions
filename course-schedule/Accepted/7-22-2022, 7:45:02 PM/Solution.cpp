// https://leetcode.com/problems/course-schedule

class Solution {
public:
   
    vector <int> adj[2005];
    int color[2005];
    bool cyclefound = false ;
    
    
    void dfs(int u ){
        if(color[u] !=0)
            return;
        color[u] =1 ;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(color[v] == 1){
                cyclefound = true ;
                return ;
            }
            if(color[v] == 0){
                dfs(v);
            }
        }
        color[u] = 2;
    }
    
    
    
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        for(int i =0 ;i<prerequisites.size();i++){
            int u = prerequisites[i][0];int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        for(int i =0 ;i<n+1;i++)
            color[i] =0 ;
        
        for(int i =0 ;i<n;i++){
            if(color[i] == 0){
                dfs(i);
            }
        }
        
        return !cyclefound  ;
    }
};