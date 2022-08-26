// https://leetcode.com/problems/connecting-cities-with-minimum-cost

class Solution {
public:
    static bool comp( vector <int> &a , vector <int> &b){
        return a[2]< b[2];
    }
    int find(vector <int> &parent,int i){
        while(parent[i]!=i){
            i = parent[i];
        }
        return i;
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
      sort(connections.begin(),connections.end(),comp);
      int nodes =0;
      int cost =0;
       vector <int> parent(n+2,0);
        for(int i =0;i<n+2;i++){
            parent[i]=i;
        }
      for(int i =0;i<connections.size();i++){
          vector <int> vec  = connections[i];
          int u = vec[0];int v= vec[1];int w = vec[2];
          int root1 =find(parent ,u);
          int root2 = find(parent ,v);
          if(root1 != root2){ // not going to form a cycle so include this in mst
              cost+=w;
              parent[u]=root2;
              nodes++;
          }
          if(nodes == n-1) return cost;
      }  
     return -1;   
    }
};