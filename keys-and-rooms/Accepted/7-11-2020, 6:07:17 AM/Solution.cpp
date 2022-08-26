// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    vector <int> adj[100005];
    bool visited[100005];
    void dfs(int u){
        if(!visited[u]){
            visited[u]=1;
        }
        for(int i=0;i<adj[u].size();i++){
            int v= adj[u][i];
            if(!visited[v])
                dfs(v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = rooms.size();
        if(sz ==0)
            return true;
        
        for(int i=0;i<sz;i++){
            for(int j =0;j<rooms[i].size();j++){
               adj[i].push_back(rooms[i][j]); 
            }
        }
        for(int i=0;i<sz;i++){
            visited[i]=false;
        }
        dfs(0);
        for(int i=0;i<sz;i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};