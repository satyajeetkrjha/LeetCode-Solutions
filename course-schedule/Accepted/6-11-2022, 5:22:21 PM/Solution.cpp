// https://leetcode.com/problems/course-schedule

class Solution {
public:
    int color[10005];
    vector <int> adj[10005];
    bool flag = false ;
    
    void dfs(int u ){
        if(color[u] !=0)
            return ;
        color[u] =1 ;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(color[v] == 1){
                flag = true ;
                return;
            }
            if(color[v] == 0)
                dfs(v);
        }
        
        color[u] = 2;
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        for(int i =0 ;i< numCourses ;i++){
            color[i] =0;
        }
        
       
        for(int i =0 ;i< numCourses ;i++){
            if(color[i] == 0){
                dfs(i);         
            }
            if(flag)
                break;
        }
       return flag  ? false :true ;
        
    
        
    }
};