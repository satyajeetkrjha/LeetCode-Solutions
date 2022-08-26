// https://leetcode.com/problems/redundant-connection

class Solution {
public:
     vector <int> parent ;
    int findParent(int u){
       while(parent[u]!=u){
           u = parent[u];
       } 
        return u ;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
       
        parent.resize(n+2);
        for(int i =1 ;i<=n;i++) parent[i] =i;
        vector <int> res ;
       
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0];int v = edges[i][1];
            int p1 = findParent(u);
            int p2 = findParent(v);
            
            if(p1 == p2){
                res.push_back(u);
                res.push_back(v);
                break;
            }
            parent[p1] = p2 ;
            
        }
        return res ;

        
    }
};