// https://leetcode.com/problems/network-delay-time


class Solution {
public:
    #define pii pair<int,int>
    vector <pii> adj[100005];
    int visited[100005];
    int dist[100005];
    void dijkistra(int n){
        priority_queue <pii,vector<pii>,greater<pii>> q;
        q.push({0,n});
        dist[n]=0;
        while(!q.empty()){
            int distance =q.top().first;
            int node =q.top().second;
            q.pop();
            if(visited[node]){
                continue;
            }
            visited[node]=1;
            for(auto x:adj[node]){
                int newnode =x.first;
                int newdist =x.second;
                if(newdist+distance<dist[newnode]){
                    dist[newnode]=distance+newdist;
                    q.push({dist[newnode],newnode});
                }
            }
        }
        
        
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int n =times.size();
        for(int i=0;i<n;i++){
            int u= times[i][0];
            int v =times[i][1];
            int w =times[i][2];
            adj[u].push_back({v,w});
        }
        for(int i=1;i<=N;i++){
            visited[i]=0;
            dist[i]=INT_MAX;
        }
        dijkistra(K);
        int max_val =0;
        for(int i=1;i<=N;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            max_val=max(max_val,dist[i]);
        }
        return max_val;
        
    }
};