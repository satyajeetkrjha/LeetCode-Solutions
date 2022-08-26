// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    
    // to connect two connected components ,u need one edge and to connect threee connected components ,u need two edge
    vector<int> adj[100005];
    bool visited[100005];
    void dfs (int u){
       if(visited[u])
           return;
        visited[u]=true;
        for(int  i =0;i<adj[u].size();i++){
            int v= adj[u][i];
            if(!visited[v])
                dfs(v);
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        for(int i =0;i<n;i++){
            adj[i].clear();
        }
        for(int i =0;i<n;i++){
            visited[i]=false;
        }
        for(int i =0;i<connections.size();i++){
            vector <int> vec= connections[i];
            for(int j =0;j<vec.size();j++){
                int u =vec[0];int v = vec[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
      
        int ans =0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                dfs(i);
                ans++;
            }
        }
        return ans-1 ;
        
        
    }
};