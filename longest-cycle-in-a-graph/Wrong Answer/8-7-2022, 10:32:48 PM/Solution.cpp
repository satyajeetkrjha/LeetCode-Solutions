// https://leetcode.com/problems/longest-cycle-in-a-graph

class Solution {
public:
    bool flag = false ;
    int color[100005];
    vector <int> adj[100005];
    
    void dfs(int u ,int &count){
        if(color[u] == 0)
            color[u] =1 ;
         count ++;
        for(int i =0 ;i< adj[u].size();i++){
            int v = adj[u][i];
            if(color[v] == 1){
                flag = true ;
                return;
            }
            if(color[v] == 0)
                dfs(v,count);
        }
        color[u] =2 ;
    }
    
    
    int longestCycle(vector<int>& edges) {
        for(int i =0 ;i<edges.size();i++){
            if(edges[i] == -1)
                continue ;
            else
                adj[i].push_back(edges[i]);
        }
        int ans =0 ;
        memset(color,0,sizeof(color));
        for(int i =0 ;i<edges.size() ;i++){
            
            int count =0 ;
            if(color[i] == 0){
                dfs(i,count);
            }
            ans = max(ans ,count);
                
        }
        
        if(flag == false)
            return -1;
        return ans-1 ;
        
        
    }
};