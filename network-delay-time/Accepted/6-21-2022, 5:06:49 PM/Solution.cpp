// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    
    
    int dist[100005];
    int visited[100005];
    vector <pair <int ,int> > adj[100005];
    
    void dijkistra(int u){
     priority_queue <pair<int,int> ,vector <pair <int ,int> > ,greater <pair <int,int>>>pq;
        dist[u] =0 ;
        pq.push({0,u});
        while(!pq.empty()){
           auto cur = pq.top();
           pq.pop();
           int weight = cur.first ;
           int node = cur.second ;
            if(visited[node]){
                continue ;
            }
           for(auto &[newnode,newdist]:adj[node]){
               if(dist[newnode] > newdist+weight){
                   dist[newnode] = newdist+ weight;
                   pq.push({dist[newnode],newnode});
               }
           }
        }
        
    }
    
   
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        for(int i =0 ;i<times.size();i++){
            int u = times[i][0] ;
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w}); 
        }
        
        for(int i =1 ;i<=n;i++){
            dist[i] = INT_MAX;
            visited[i] =0;
        }
        
        int maxval = INT_MIN;
        dijkistra(k); // run a dijkistra from kth node
        for(int i =1 ;i<=n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxval = max(maxval ,dist[i]);
            
        }
        return maxval ;
        
        
        
    }
};