// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
   
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector <vector <vector <int>>> adj(n);
        int sz =flights.size();
       
        for(int i=0;i<sz;i++){
            vector <int> vi = flights[i];
            for(int j=0;j<vi.size();j++){
                int u =vi[0];int v=vi[1];int w=vi[2];
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
            cout<<"sz is "<<adj[cur_node].size()<<endl;
            for( auto p:adj[cur_node]){
               
                if(cur_k+1<=K && p[1]+cur_amount <minCost){
                    q.push({p[0],p[1]+cur_amount,cur_k+1});
                }
            }
        }
        return minCost==INT_MAX?-1:minCost;   
    }
};