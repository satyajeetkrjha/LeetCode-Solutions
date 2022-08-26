// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    vector <int> adj[2005];
    bool visited[2005];
    void dfs(int u ){
        cout<<"dfs vertex u is "<<u<<endl;
        if(visited[u])
            return ;
        visited[u] =true;
        cout<<"adj[u].size is "<<adj[u].size()<<endl;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            cout<<"v is "<<v<<endl;
            if(!visited[v]){
                dfs(v);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++)
            visited[i]=false;
        
        for(int i=0;i<edges.size();i++){
            vector <int> edge  = edges[i];
            int u = edge[0];int v = edge[1];
            cout<<"u is "<<u<<endl;
            cout<<"v is "<<v<<endl;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                cout<<"start node is "<<i<<endl;
                dfs(i);
                c++;
            }
        }
        
        return c;
        
    }
};