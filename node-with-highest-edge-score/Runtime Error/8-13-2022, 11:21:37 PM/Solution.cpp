// https://leetcode.com/problems/node-with-highest-edge-score


class Solution {
public:
    int scores[100005];
    vector <int> adj[100005];
    bool visited[100005];
    
    void dfs(int u ){
        if(!visited[u])
            visited[u] = true;
        for(int i =0;i< adj[u].size();i++){
              int v = adj[u][i];
             if(visited[v] || v == u) continue;
              scores[v]+=u;
               cout <<"scores[v] is "<< scores[v] << "and u is "<< u << " and v is "<< v <<  endl;
              dfs(v);  
        }
  }
    int edgeScore(vector<int>& edges) {
        /*
        memset(visited,false,sizeof(visited));
        int n = edges.size();
        for(int i = 0 ;i<n;i++){
            int node = edges[i];
            adj[i].push_back(node);
        }
    
        for(int i =0 ;i<n;i++){
                dfs(i);
            //memset(visited,false,sizeof(visited));
        }
        
        
        int node;
        
        for(int i =0 ;i<n;i++){
            cout << scores[i]<<" ";
        }
        cout << endl;
        */
         int n = edges.size();
        for(int i =0 ;i<edges.size();i++){
            scores[edges[i]]+= i;
        }
        /*
         for(int i =0 ;i<n;i++){
            cout << scores[i]<<" ";
        }
        cout << endl;
        */
        int ans = INT_MIN ;
        int node=0 ;
        for(int i =n ;i>=0;i--){
            if(scores[i]>=ans){
                ans = scores[i];
                node = i;
            }
        }
        
        
       
        
        return node ;
    }
};