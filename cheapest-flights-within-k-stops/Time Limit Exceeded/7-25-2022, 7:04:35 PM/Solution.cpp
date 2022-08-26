// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    vector <pair <int ,int> > adj[105];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        for(int i =0 ;i<flights.size();i++){
            vector <int> temp = flights[i];
            int u = temp[0];int v = temp[1];int w = temp[2];
            adj[u].push_back({v,w});
        }
        
        queue <vector <int> > q;
        q.push({src,0,-1});
        int minCost = INT_MAX;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int cur_node = cur[0];int cur_weight = cur[1];int curK = cur[2];
            if(cur_node == dst){
                minCost = min(minCost ,cur_weight);
                continue;
            }
            for(auto [neighbor,weight]:adj[cur_node]){
                if(curK+1 <=K && cur_weight+weight <minCost){
                    q.push({neighbor,cur_weight+weight,curK+1});
                }
            }
            
        }
        return minCost==INT_MAX?-1:minCost;   

    }
};