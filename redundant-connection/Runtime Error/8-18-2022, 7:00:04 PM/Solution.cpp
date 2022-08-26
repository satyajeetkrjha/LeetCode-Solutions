// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector <int> parent;
    
    int findparent(int u){
        cout <<"u inside "<< u << endl;
        while(u!=parent[u]){
            u = parent[u];
        }
        return u ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(100);
        for(int i =0 ;i<100;i++)
            parent[i] = i;
        
        vector <int> res ;
        for(int i =0 ;i<n;i++){
            int u = edges[i][0];int v = edges[i][1];
            cout <<"u and v are "<< u << " "<< v << endl;
            int p1 = findparent(u);
            int p2 = findparent(v);
            cout <<"p1 "<<p1<<endl;
            cout <<"p2 "<<p2<< endl;
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