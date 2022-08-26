// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    
    vector <int> adj[100005];
     map <int ,int> visited;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
            for(int i =0 ;i<edges.size();i++){
                int u = edges[i][0];int v = edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
          set <int> s ;
        for(auto it:restricted){
            s.insert(it);
        }
       
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
                    if(s.count(v)>0)
                       continue ;
                   if(!visited[v]){
                       visited[v]  =1;
                       q.push(v);
                   }
               }
           }
        return count ;
        
    }
};