// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    
    vector <pair <int ,int> > adj[100005];
    vector <int> visited ;
    vector <int> dist;
 
priority_queue <pair <int ,int> ,vector<pair <int ,int>>,greater <pair <int,int>> >pq ;
    void dijkistra(int u){
        dist[u] = 0 ;
        pq.push({0,u});
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            int weight = cur.first;
            int node = cur.second ;
            for(auto[v,w]:adj[node]){
                if(dist[v] > w+weight){
                    dist[v] = w+weight ;
                    pq.push({dist[v],v});
                }
            }
        }
        
    }
    
    
    
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
        for(int i =0 ;i<times.size() ;i++){
            int u = times[i][0] ;int v = times[i][1];int w = times[i][2];
            adj[u].push_back({v,w});
        }
        visited.resize(n+2,-1);
        dist.resize(n+2,INT_MAX);
        
        dijkistra(k);
        int maxval = INT_MIN;
        for(int i =1 ;i<=n;i++){
            if(dist[i] == INT_MAX)
                return -1;
            maxval = max(maxval ,dist[i]);
        }
        return maxval ;
        
    }
};