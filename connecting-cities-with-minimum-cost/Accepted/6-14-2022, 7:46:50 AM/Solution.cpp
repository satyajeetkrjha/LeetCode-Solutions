// https://leetcode.com/problems/connecting-cities-with-minimum-cost

class Solution {
public:
    
    static bool compare(vector <int> &a ,vector<int> &b){
        return a[2]<b[2];
    }
    
    vector <int> parent ;
    
    int findparent (int u){
        while(parent[u]!=u){
            u = parent[u];
        }
        return u ;
    }
    
    
    
    
    int minimumCost(int n, vector<vector<int>>& connections) {
     
        sort(connections.begin(),connections.end(),compare);
        
        parent.resize(n+2);
        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
        
        
        int cost = 0;
        int edgestaken = 0;
        for(int i =0 ;i< connections.size();i++){
            vector <int> temp = connections[i];
            int u = temp[0];int v = temp[1];int w = temp[2];
            int p1 = findparent(u);
            int p2 = findparent(v);
            if(p1!=p2){
                cost+= w;
                edgestaken++;
                parent[p1] = p2 ; // most crucial
            }
        }
    
        if(edgestaken == n-1){
            return cost ;
        }
        return -1;
        
        
        
    }
};