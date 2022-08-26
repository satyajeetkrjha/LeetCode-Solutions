// https://leetcode.com/problems/course-schedule

class Solution {
public:
    vector <int> adj[100005];
    bool visited[100005];
    bool flag;
    void dfs(int u){
        cout<<"u in dfs  is "<<u<<endl;
        if(visited[u] == 0){
            visited[u]=1;
        }
        for(int i=0;i<adj[u].size();i++){
            int v =adj[u][i];
            cout<<"u is "<<u<<endl;
            cout<<"v is "<<v<<endl;
            if(visited[v]==1){
                cout<<"flag marked true for v "<<v<<endl;
                flag =true;
            }
            if(visited[v]==0){
                visited[v]=1;
                dfs(v);
            }
        }
        cout<<"u marked 2 is "<<u<<endl;
        visited[u]=2;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int sz =prerequisites.size();
        flag =false;
        for(int i=0;i<sz;i++){
            int u =prerequisites[i][0];
            int v =prerequisites[i][1];
            adj[v].push_back(u);
        }
        bool visited[numCourses+1];
        for(int i=0;i<numCourses;i++){
            visited[i]=0;
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0)
                dfs(i);
        }
         if(flag ==true)
        return false;
    else 
        return true;
    }
   
};