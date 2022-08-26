// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector <vector<int> > ans;
    bool visited[1000];
    void dfs(vector<vector<int>>& graph,vector <int> temp,int node,int n){
        cout<<"node is "<<node<<endl;
        if(node ==n){
            cout<<"condition match"<<endl;
            temp.push_back(node);
            ans.push_back(temp);
            return;
        }
        visited[node] =true;
        temp.push_back(node);
        cout<<"node pushed in vector is "<<node <<endl;
        for(int i=0;i<graph[node].size();i++){
            int adjacentnode=graph[node][i];
            if(visited[adjacentnode]==false){
                dfs(graph,temp,adjacentnode,n);
            }
        }
        visited[node]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
        int n=graph.size();
        if(n ==0)
            return ans;
        
        vector <int> temp;
        bool visited[n+1];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        dfs(graph,temp,0,n-1);
        return ans;
        
    }
};