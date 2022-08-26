// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    vector <int> adj[100005];
    bool visited[100005];
    void dfs(int u ){
        if(!visited[u]){
            visited[u]=true;
        }
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                dfs(v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int count =0;
        if(n ==0)
            return count ;
        for(int i=0;i<n;i++){
            for(int j= 0;j<M[i].size();j++){
                if(M[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
            for(int i=0;i<n;i++){
                visited[i]=false;
            }
        
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    dfs(i);
                    count++;
                }
            }
            return count ;
            
        }
        
};