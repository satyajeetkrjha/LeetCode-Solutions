// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    
    
    map <string ,priority_queue <string ,vector <string >,greater <string >>> adj;
    
    
    void dfs( string node ,map <string ,priority_queue <string ,vector <string >,greater <string >>> &adj,vector <string> &res){
        
        while(adj[node].size() >0){
            auto neighbor = adj[node].top();
            adj[node].pop();
            dfs(neighbor,adj,res);
        }
        
        cout <<"node is "<< node << endl;
      
        res.push_back(node);
             
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
     
        for(auto it :tickets){
          string u = it[0] ;string v = it[1];
          adj[u].push(v);
        } 
        
      vector <string > res ;
      dfs("JFK",adj,res);
      
    
      reverse(res.begin(),res.end());
      return res ;
    }
};