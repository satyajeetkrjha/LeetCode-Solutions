// https://leetcode.com/problems/replace-elements-in-an-array

class Solution {
public:
    
     unordered_map <int ,int> m;
     bool flag = false ;
     int color[100005];
     vector <int> adj[100005];
    
    
     void dfs(int u){
         cout <<"u ...."<< u << endl;
         if(color[u] == 0)
             color[u] =1 ;
         //cout <<"u is "<< u << endl;
         for(int i =0 ;i<adj[u].size();i++){
             int v = adj[u][i];
             if(color[v] == 0){
                 dfs(v);
             }
             else if(color[v] ==1){
                 flag = true;
                 return ;
             }
         }
         color[u] =2 ;
     }
    
    
    
    
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
       
        for(int i =0 ;i <operations.size();i++){
            int u = operations[i][0] ;int v = operations[i][1];
            m[u] = v;
            adj[u].push_back(v);
        }
        
        memset(color,0,sizeof(color));
        
       // cout <<"now is "<< m.begin()->first << endl;
        dfs(m.begin()->first);
        
       // cout <<"flag is "<< flag << endl;
        
        if(!flag){
            for(int i=0 ;i<nums.size();i++){
                if(m[nums[i]]){
                    nums[i] = m[nums[i]];
                }
            }
        }
        else{
            int n = nums.size();
            for(int i =0 ;i<(nums.size()/2) ;i++){
                swap(nums[i],nums[n-i-1]);
            }
        }
        return nums ;
        
    }
};