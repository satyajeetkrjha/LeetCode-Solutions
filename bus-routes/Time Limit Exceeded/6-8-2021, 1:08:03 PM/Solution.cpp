// https://leetcode.com/problems/bus-routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector <vector <int>> adj(100900);
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                int bus =i+100001;
                cout<<"j is "<<j <<" bus is "<<bus<<endl;
                cout<<"routes[j] is "<<routes[i][j]<<endl;
                adj[bus].push_back(routes[i][j]);
                adj[routes[i][j]].push_back(bus);
            }
        }
        
        queue <int> qs;
        qs.push(source);
        vector <int> dist(100900);
        dist[source] =1;
        while(!qs.empty()){
            int u =qs.front();
            qs.pop();
            cout<<"u is "<<u<<endl;
            if( u == target )
                return dist[u]/2;
            for(int i=0;i<adj[u].size();i++){
                int v =adj[u][i];
                
                if(!dist[v]){
                cout<<"u here is "<<u<<endl;
                cout<<"v here is "<<v<<endl;
                    dist[v]=dist[u]+1;
                    qs.push(v);
                }
            }
        }
        return -1;
        
    }
};