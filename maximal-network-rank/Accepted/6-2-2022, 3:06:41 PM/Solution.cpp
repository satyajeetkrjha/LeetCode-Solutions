// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      
        int count[105];
        int mat[105][105]; 
        memset(mat,0,sizeof(mat));
        memset(count ,0,sizeof(count));
        
        for(auto edges: roads){
            int u = edges[0];
            int v = edges[1];
            
             count[u]++;
             count[v]++;
             mat[u][v] =1 ;
             mat[v][u] = 1 ;
        }
        
      
        int ans = INT_MIN;
        for(int i =0 ;i< n;i++){
            for(int j = i+1;j<n;j++){
                int sum = count[i]+ count[j]+ (mat[i][j] ==1 ? -1:0);
                ans = max(ans ,sum);
            }
        }
        return ans ;
        
        
        
    }
};