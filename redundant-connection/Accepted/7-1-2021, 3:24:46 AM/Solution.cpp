// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    int find( vector <int> & parents ,int i){
       while(parents[i]!=i){
           i = parents[i];
       }
        return i;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector <int> parents(n+2,0);
        for(int i =1;i<=n;i++){
            parents[i] =i;
        }
        vector <int> temp;
        for(int i =0;i<edges.size();i++){
            vector <int> nodes = edges[i];
            int u = nodes[0];int v = nodes[1];
            int f1 = find(parents ,u);
            int f2 = find(parents ,v);
            
            if(f1 == f2){
                temp.push_back(u);
                temp.push_back(v);
                break;
            }
            parents[f1]=f2;
        }
        return temp;
    }
};