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
      
       vector <int> parent(n+1,0);
        for(int i =1;i<=n;i++){
            parent[i]=i;
        }
      int nodes =0;
      int  cost =0;
      for(int i =0;i<connections.size();i++){
          vector <int> vec  = connections[i];
          int u = vec[0];
          int v= vec[1];
          int w = vec[2];
          // cout<<"vec.size is "<<vec.size()<<endl;
          int root1= find(parent ,u);
          int root2 = find(parent ,v);
          if(root1!=root2){
              cost+=w;
              nodes++;
              parent[u]=v;
          }
          if(nodes == n-1) return cost;
      }  
     return -1;   
    }
};