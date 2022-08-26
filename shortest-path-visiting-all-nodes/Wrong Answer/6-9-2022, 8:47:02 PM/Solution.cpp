// https://leetcode.com/problems/shortest-path-visiting-all-nodes

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        if( n  == 0)
            return 0;
        int finalstate  =  (1<< n) -1 ; // if 3 then 111 and if 4 then 1111
        
        queue <pair <int ,int> > q ; // node and bit state
       
        vector <vector <int> > visited(n,vector <int> (finalstate+1,0));
       
        for(int i =0 ;i< n;i++){
            q.push({i,1 <<i});
        }
        
        int ans =0 ;
        
        while(!q.empty()){
            
            int sz = q.size();
             ans++;
            for(int i =0 ;i<sz;i++){
              auto cur = q.front();
              q.pop();
            int node = cur.first ;
            int curnodebitstate = cur.second ;
            for(auto neighbor :graph[node]){
                int newvisitednodebitstate = curnodebitstate | ( 1<< neighbor);
                if(visited[neighbor][newvisitednodebitstate]  == 1){
                    continue;
                }
                visited[neighbor][newvisitednodebitstate] = 1;
                
                if(newvisitednodebitstate == finalstate)
                    return ans ;
                q.push({ neighbor,newvisitednodebitstate});
            }
          }
            
        }
        return -1;
    }
};