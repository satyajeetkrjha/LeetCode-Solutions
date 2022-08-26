// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    
    vector <int> adj[100005];
    int visited[100005];
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
            for(int i =0 ;i<edges.size();i++){
                int u = edges[i][0];int v = edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        memset(visited,false,sizeof(visited));
            queue <int> q ;
            q.push(0);
        int count =0;
        visited[0] = 1;
           while(!q.empty()){
               auto cur = q.front();
               q.pop();
               count++;
               for(int i =0;i<adj[cur].size();i++){
                   int v = adj[cur][i];
                   if(std::find(restricted.begin(), restricted.end(),v)!=restricted.end())
                       continue ;
                   if(!visited[v] &&  std::find(restricted.begin(), restricted.end(),v)==restricted.end()){
                       visited[v]  =1;
                       q.push(v);
                   }
               }
           }
        return count ;
        
    }
};