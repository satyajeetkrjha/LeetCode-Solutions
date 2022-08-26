// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    
    unordered_map<string,vector <pair <string ,double>>>adj ;
    
    
    double bfs(string start ,string end){
         set<string> visited ;
         queue<pair<string ,double> > q;
         q.push({start,1});
         visited.insert(start);
         while(!q.empty()){
             auto node = q.front();
             q.pop();
             for(auto element :adj[node.first]){
                 string neighbour = element.first ;
                 double cost = element.second ;
                 if(neighbour == end){
                     return node.second* cost;
                 }
                 if(visited.find(neighbour) == visited.end()){
                     visited.insert(neighbour);
                     q.push({neighbour, cost*node.second});
                 }   
             }
         }
      return -1;        
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
      
        vector <double> res ;
        
       for(int i =0 ;i<equations.size();i++){
           vector <string> temp = equations[i];
           string u = temp[0];string v = temp[1];
           adj[u].push_back({v,values[i]});
           adj[v].push_back({u,1/values[i]});
       }
        for(auto q: queries){
            string u = q[0] ;string v = q[1];
            // both start and final node exits in the graph
            if(adj.find(u)!= adj.end() && adj.find(v)!=adj.end()){
                res.push_back(bfs(u,v));
            }
            else{
                res.push_back(-1);
            }
        }
        return  res ;
        
        
        
    }
};