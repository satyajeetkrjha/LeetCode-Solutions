// https://leetcode.com/problems/course-schedule

class Solution {
public:
    int color[100005];
    vector <int> adj[100005];
    bool cycle = false;
    void dfs(int u){
        if(color[u]!=0)
            return;
        color[u] = 1;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(color[v] == 1){
                cycle = true;
                return;
            }
            else if(color[v] == 0){
                dfs(v);
            }
        }
        color[u] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        for(int i =0 ;i<n;i++){
            int u = prerequisites[i][0];int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i =0 ;i<numCourses ;i++){
            color[i] = 0;
        }
        
        for(int i = 0 ;i< numCourses;i++){
            if(color[i] == 0){
                dfs(i);
            }
        }
        return !cycle ;
    }
};