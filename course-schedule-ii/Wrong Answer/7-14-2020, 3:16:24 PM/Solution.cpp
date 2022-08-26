// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    bool flag =false;
    vector <int> adj[100005];
    vector <int> ans;
    int  visited[100005];
    stack<int> s;
    void cycle(int u){
        if(visited[u]==0)
            visited[u]=1;
        for(int i=0;i<adj[u].size();i++){
            int v =adj[u][i];
            if(visited[v]){
                flag =true;
                return;
            }
            if(visited[v] ==0){
                visited[v]=1;
                cycle(v);
            }
        }
        visited[u]=2;
    }
    void dfs (int u){
        if(visited[u] ==0)
            visited[u]=1;
        for(int i=0;i<adj[u].size();i++){
            int v =adj[u][i];
            if(visited[v] ==0){
                visited[v]=1;
                dfs(v);
            }
                
        }
        s.push(u);
    }
    void printvector (vector <int> &v){
        for(int i =0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       int n = prerequisites.size();
        if(n ==0)
            return ans;
       for(int i=0;i<numCourses;i++)
           visited[i]=0;
        
       for(int i=0;i<n;i++){
           adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
       }
        // first check if there is a cycle or not.If there is a cycle no point doimg toposort
        for(int i=0;i<numCourses;i++){
            if(visited[i] ==0 )
                cycle(i);
        }
        if(flag)
            return ans;
        for(int i=0;i<numCourses;i++){
            visited[i]=0;
        }
        
        // now do dfs and push in stack 
        for(int i=0;i<numCourses;i++){
            if(visited[i] ==0)
                dfs(i);
        }
        while(!s.empty()){
            int val = s.top();
            s.pop();
            ans.push_back(val);
        }
        return ans ;
        
        
    }
};