// https://leetcode.com/problems/shortest-path-visiting-all-nodes

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n =  graph.size();
        queue <pair <int ,int> > q ; // node and bit state 
        int finalstate = (1 << n )-1;
        vector <vector <int> > visited(n,vector <int>(finalstate+1,0));
        
        for(int i =0 ;i<n;i++){
            q.push({i,1 <<i});
        }
        
        int ans =0;
        while(!q.empty()){
            int sz = q.size();
            ans ++;
            for(int i  =0 ;i<sz;i++){
                auto cur  = q.front();
                q.pop();
                int node = cur.first ;
                int curnodestae = cur.second ;
                for(auto neighbor :graph[node]){
                    // set ith bit in cur state to 
                    int neighborstate = curnodestae | (1 << neighbor);
                    if(visited[neighbor][neighborstate]){
                        continue ;
                    }
                    if(neighborstate == finalstate){
                        return ans ;
                    }
                    visited[neighbor][neighborstate] = 1;
                    q.push({neighbor,neighborstate});
                }
            }
        }
        return -1;    
    }
};