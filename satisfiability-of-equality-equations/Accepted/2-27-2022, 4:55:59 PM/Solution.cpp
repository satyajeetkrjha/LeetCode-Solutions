// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    vector <int> adj[10005];
    int color[10005];
    int visited[10005] ;
    void dfs(int u ,int col){
       color[u] = col;
       visited[u] = true;
        for(int i =0 ;i< adj[u].size();i++){
           int v = adj[u][i];
            if(!visited[v]){
               dfs(v,col);  
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        
        for(int i =0 ;i< n+1;i++){
            visited[i] = false;
            color[i] = INT_MAX;
        }
        
        for(int i =0 ;i<n ;i++){
            string temp = equations[i];
             int u = temp[0]-'a';
             int v = temp[3]-'a';
            if(temp[1] =='='){
              adj[u].push_back(v);
              adj[v].push_back(u); 
            }
        }
        int col =0;
        for(int i =0 ;i< 26 ;i++){
            if(!visited[i]){
                dfs(i,col);
            }
            col++;
        }
        
        for(int i =0 ;i< n;i++){
            string temp = equations[i];
            if(temp[1] == '!'){
                 int u = temp[0]-'a';
                 int v = temp[3]-'a';
                 if(color[u] == color[v] && color[u]!=INT_MAX){
                     return false;
                 }
            }
            
        }
        return true ;
    }
};