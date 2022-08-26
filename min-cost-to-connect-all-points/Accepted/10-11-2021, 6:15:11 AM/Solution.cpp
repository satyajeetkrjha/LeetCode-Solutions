// https://leetcode.com/problems/min-cost-to-connect-all-points

#include <algorithm>
vector <int> parent ;
vector <int> ranks;
class Node{
  public:
  int u ,v,w ;
  Node(int x ,int y ,int z){
      u = x;
      v= y ;
      w=z;
  }
};
    
    int find(int u){
        if(parent[u] == u){
            return u ;
        }
        return parent[u] =find(parent[u]);
    }
    void unionfun(int x ,int y){
        int u = find(x);
        int v = find(y);
        
        if(ranks[u]> ranks[v]){
            parent[v]=u;
        }
        else if(ranks[v]> ranks[u]){
            parent[u] = v;
         }
        else{
            parent[u]=v;
            ranks[v]++;
        }
        
    }

class Solution {
public:
    static bool compweight(const Node first ,const Node second){
        return first.w <second.w;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
     
      vector <Node> V ;
      for(int i =0 ;i<points.size()-1;i++){
          for(int j = i+1;j<points.size();j++){
          int dist = abs(points[j][0]- points[i][0])+
                  abs(points[j][1] -points[i][1]);
          V.push_back(Node(i,j,dist));
         
           }
      }
        parent.resize(V.size()+1);
        ranks.resize(V.size()+1);
        
        sort(V.begin(),V.end(),compweight);
        for(int i =0 ;i<=V.size();i++){
            parent[i]=i;
            ranks[i]=0;
        }
        
        int totaledges = V.size();
        int totalcost =0;
        for(int i =0 ;i<totaledges ;i++){
            int u = V[i].u;int v = V[i].v ;int w = V[i].w ;
            if(find(u)!=find(v)){
                totalcost+= w;
                unionfun(u ,v);
            }
        }
       return totalcost ;
    }
};