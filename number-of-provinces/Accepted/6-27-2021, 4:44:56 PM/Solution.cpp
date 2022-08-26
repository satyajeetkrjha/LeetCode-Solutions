// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    bool visited[205];
    void dfs(vector<vector<int>>& isConnected,int i){
         int n = isConnected.size();
         for(int j =0;j<n;j++){
             if(isConnected[i][j] ==1 && visited[j] ==false){
                 visited[j]=true;
                 dfs(isConnected,j);
             }
         }
         
         
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        memset(visited,false,sizeof(visited));
        int ans =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i);
                ans++;
            }
        }
        return ans;
        
    }
};