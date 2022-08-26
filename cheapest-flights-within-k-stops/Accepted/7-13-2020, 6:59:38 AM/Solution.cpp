// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
   
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector <vector <vector <int>>> adj(n);
        int sz =flights.size();
       
        for(auto f : flights) {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            adj[from].push_back({to, cost});
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
               
                if(cur_k+1<=K && p[1]+cur_amount <minCost){
                    q.push({p[0],p[1]+cur_amount,cur_k+1});
                }
            }
        }
        return minCost==INT_MAX?-1:minCost;   
    }
};