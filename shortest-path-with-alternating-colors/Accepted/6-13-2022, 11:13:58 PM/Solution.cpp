// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
      vector<int> adjred[n];
      vector<int> adjblue[n];
      
        for(int i =0;i<redEdges.size();i++){
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            adjred[u].push_back(v);
        }
        
        for(int i =0 ;i<blueEdges.size() ;i++){
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            adjblue[u].push_back(v);
        }
        
        
        queue <pair <int ,int> > q ; // node and the edge color
        q.push({0,1}); // red and blue color
        q.push({0,-1});
        
        /*
        really good structure because now for all nodes you can store distance
        if that distance includes a red edge as last edge and seond one in pair stores the distance when blue edge is the last edge
        */
        vector <pair <int,int> > res ;
        res.resize(n,{INT_MAX,INT_MAX});
        res[0] ={0,0};
        int dist =0;
        while(!q.empty()){
             int sz = q.size();
             for(int i =0 ;i<sz;i++){
                 auto [node,color] = q.front();
                 q.pop();
                 if(color == 1){
                     for(auto neigh :adjblue[node]){
                         if(res[neigh].second > dist+1){
                             res[neigh].second = dist+1;
                             q.push({neigh,-1});
                         }
                     }
                 }
                 else{
                     for(auto neigh :adjred[node]){
                         if(res[neigh].first>dist+1){
                             res[neigh].first = dist+1;
                             q.push({neigh,1});
                         }
                     }
                 }
             }
            dist++;
        }
        vector <int> ans ;
        for(int i =0 ;i< n;i++){
            int val = min(res[i].first,res[i].second);
            if(val == INT_MAX)
                val = -1;
            ans.push_back(val);
        }
        return ans;
        
    }
};