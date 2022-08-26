// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    
    vector <int> adj[100005];
    
    void dfs(vector<int> &visited ,int u){
        if(visited[u])
            return;
          visited[u] =1 ;
          for(int i =0 ;i<adj[u].size();i++){
              int v = adj[u][i];
              if(!visited[v]){
                  dfs(visited ,v);
              }
          }    
    }
    
    
    
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        for(int i =0 ;i< n;i++){
            vector <int> temp = rooms[i];
            for(int j =0 ;j< temp.size();j++){
               int u = temp[j];
                adj[i].push_back(u);
            }
        }
        
        vector <int> visited;
        visited.resize(n,0);
        dfs(visited,0);
        
        for(int i =0 ;i< n;i++){
            if(!visited[i])
                return false;
        }
        return true ;
        
    }
};