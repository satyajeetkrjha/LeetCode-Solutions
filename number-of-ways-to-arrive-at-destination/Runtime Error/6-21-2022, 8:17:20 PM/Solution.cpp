// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

typedef long long int ll ;
class Solution {
public:
    const int mod = 1e9+7;
    vector <pair <int ,int> > adj[10005];
    ll dist[100005];
    ll ways[100005];
    void dijkistra(int u){
        priority_queue<pair <int ,int> ,vector <pair <int ,int> > ,
        greater<pair <int ,int> >> pq ;
        for(int i =0 ;i<10005;i++){
            dist[i] = LONG_MAX;
        }
        memset(ways ,0,sizeof(ways));
        dist[u] =0 ;
        ways[u] = 1;
        pq.push({0,u});
        while(!pq.empty()){
            auto[weight,node]=pq.top();
            //cout <<"weight and node are "<< weight << " "<< node << endl;
            pq.pop();
            for(auto[newnode ,newdist]:adj[node]){
                /*
                cout <<"newnode and newdist are "<< newnode << " "<< newdist << endl;
                cout << "weight + newdist is"<< weight+newdist << endl;
                cout << "dist[newnode]  "<< dist[newnode]<< endl;
                */
                if(dist[newnode] > weight +newdist){
                   // cout << "dist updated "<< dist[newnode]<< endl;
                    dist[newnode] = weight + newdist ;
                    ways[newnode] = ways[node];
                    pq.push({dist[newnode],newnode});
                }
                else if( dist[newnode] == weight + newdist){
                    ways[newnode]= (ways[newnode]+ ways[node])%mod;
                }
            }
        }
    }
    
    
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
       
        for(int i  =0 ;i< roads.size();i++){
            int u = roads[i][0];int v= roads[i][1]; int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        dijkistra(0);
        return ways[n-1];
        
        
    }
};