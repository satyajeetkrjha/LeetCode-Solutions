// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    
    void dfs(string source,
            map <string ,priority_queue <string ,vector<string> ,greater<string>>> &adj,
            vector<string> &res
           )
    {
        while(!adj[source].empty()){
            string neighbour = adj[source].top();
            adj[source].pop();
            
            dfs(neighbour,adj,res);
        }
        res.push_back(source);
        
    }
    
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       map <string ,priority_queue <string ,vector<string> ,greater<string>>> adj;
       vector <string> res ;
       
        
         for(auto node :tickets){
            adj[node[0]].push(node[1]);
        }
        dfs("JFK",adj,res);
        reverse(res.begin(),res.end());
        return res ;
        
        
    }
};