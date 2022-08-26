// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    int count;
    vector<int> parent ;
    vector <int> rank;
    int find(int x){
        if(parent[x] ==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unionfun(int x ,int y){
        int u = find(x);
        int v = find(y);
        if(u !=v){
            count --;
            if(rank[u]> rank[v]){
            parent[v] = u;
        }
         else if (rank[v]> rank[u]){
            parent[u] = v;
        }
          else{
            parent[u] = v;
            rank[v]++;
          }
            
        }
        
    }
    
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        count = n;
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0 ;i<n;i++){
            parent[i] = i;
            rank[i] =0;
        }
        for(int i =0 ;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    // form an edge so basically do union
                    unionfun(i,j);
                } 
            }
        }
        return n- count ;
    }
};