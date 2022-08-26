// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector <int> adj[2005];
    int visited[2005];
    int color[2005];
    stack <int> st ;
    bool flag = false ;
    void cycle(int u){
        color[u] =1 ;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(color[v] == 1){
                flag = true ;
                return;
            }
            if(color[u] == 0){
              cycle(u);
            }
        }
        color[u] = 2;
    }
    
    void dfs(int u){
        if(!visited[u])
            visited[u] =1 ;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v])
                dfs(v);
        }
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i =0 ;i<prerequisites.size();i++){
            int u = prerequisites[i][0] ;int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        memset(color,0,sizeof(color));
        for(int i =0 ;i<numCourses;i++){
            if(color[i] == 0){
                cycle(i);
            }
        }
        
        if(flag){
            return {} ;
        }
        
        memset(visited,false,sizeof(visited));
        for(int i =0 ;i<numCourses ;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        
        vector <int> res ;
        while(!st.empty()){
            auto ele = st.top();
            st.pop();
            res.push_back(ele);
        }
        return res ;
        
        
    }
};