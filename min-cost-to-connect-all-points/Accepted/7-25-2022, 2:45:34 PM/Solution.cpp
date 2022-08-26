// https://leetcode.com/problems/min-cost-to-connect-all-points


struct Node{
    int u ,v,w ;
    Node(int _u ,int _v ,int _w){
        u = _u ;
        v = _v;
        w = _w;
        
    }
};


vector <int> parent ;

int find(int u ){
    while(parent[u]!=u){
      u = parent[u];
    }
    return u ;
}


void unionfun(int u ,int v){
    int p1 = find(u);
    int p2 = find(v);
    if(p1 !=p2){
        parent[p1] =p2; 
    }
}



class Solution {
public:
    
    static const bool comp(const Node a ,const Node b){
        return a.w < b.w ;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        
        
        vector <Node> edges ;
        
        for(int i  =0; i< points.size();i++){
           for( int j = i+1 ;j<points.size();j++){
                int dist = abs(points[j][0]- points[i][0]) + abs(points[j][1]-points[i][1]);
                edges.push_back(Node(i,j,dist));
            }
        }
        int n = edges.size();
        sort(edges.begin(),edges.end(),comp);
        parent.resize(n+2);
        for(int i = 0 ;i<=n;i++){
            parent[i] = i ;
        }
        int cost = 0 ;
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i].u ;int v = edges[i].v;int w = edges[i].w;
            if(find(u) != find(v)){
                unionfun(u,v);
                cost += w ;
            }
        }
        return cost;
    }
};