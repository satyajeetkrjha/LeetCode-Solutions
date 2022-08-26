// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    
    void dfs(string source,map <string ,priority_queue<string ,vector<string>,greater<string>>> &adj , vector<string>&res){
        cout <<"source is ...."<< source<< endl;
        res.push_back(source);
       while(!adj[source].empty()){
          string neighbournode = adj[source].top();
           adj[source].pop();
           dfs(neighbournode,adj,res);
       }
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res ;
    map <string ,priority_queue<string ,vector<string>,greater<string>>> adj;
        
        for(auto node :tickets){
            adj[node[0]].push(node[1]);
        }
        dfs("JFK",adj,res);
        return res;
        
        
        
    }
};