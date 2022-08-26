// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       vector <vector <vector <int>>> adj(n);
       
        for(int i=0;i<flights.size();i++){
            for(int j=0;j<flights[i].size();j++){
                int u =flights[j][0];int v = flights[j][1];int w = flights[j][2];
                adj[u].push_back({v,w});
            }
        }
        queue <vector <int> > q;
        q.push({src,0,-1});
        int minCost =INT_MAX;
        while(!q.empty()){
            vector <int> cur =q.front();
            q.pop();
            int cur_node =cur[0];
            int cur_amount=cur[1];
            int cur_k=cur[2];
            if(cur_node ==dst){
                minCost=min(minCost,cur_amount);
                continue;
            }
            for( auto p:adj[cur_node]){
                int adjacent_cost=p[1];
                if(adjacent_cost+cur_amount <minCost && cur_k+1<=K){
                    q.push({p[0],adjacent_cost+cur_amount,cur_k+1});
                }
            }
        }
        return minCost==INT_MAX?-1:minCost;   
    }
};