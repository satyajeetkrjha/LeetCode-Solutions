// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n   == 1)
            return {} ;
        
        int indegree[n];
        memset(indegree ,0,sizeof(indegree));
        vector <int> adj[n];
        for(int i =0 ;i< edges.size();i++){
            int u = edges[i][0];int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++ ;
            indegree[v]++;
        }
        
        // push all leaf nodes in queue and remove them 
        queue <int> q ;
        for(int i =0 ;i<n;i++){
            if(indegree[i] == 1)
                q.push(i);
        }
        
        
        vector <int> res ;
        while(!q.empty()){
            int sz = q.size();
            res.clear();
            for(int i =0 ;i< sz;i++){
                auto cur = q.front();
                q.pop();
                res.push_back(cur);
                indegree[cur]--;
                for(auto neigh :adj[cur]){
                    indegree[neigh]--;
                    if(indegree[neigh] == 1){
                        q.push(neigh);
                    }
                } 
            }
        }
        return res ;
        
          
    }
};