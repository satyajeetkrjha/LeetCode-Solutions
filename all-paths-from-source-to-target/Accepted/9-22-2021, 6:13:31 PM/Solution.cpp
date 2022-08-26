// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    bool visited[105];
    vector <vector <int> > res ;
    void dfs(vector<vector<int>>& graph, vector <int> temp ,int u ,int destination){
        if(u == destination){
            temp.push_back(u);
            res.push_back(temp);
            return ;
        }
        if(!visited[u])
            visited[u] = true ;
        
        temp.push_back(u);
        for(int i =0 ;i<graph[u].size();i++){
            int adjacentnode = graph[u][i];
            cout<<"adjacent node is "<<adjacentnode<<endl;
            if(!visited[adjacentnode]){
                dfs(graph ,temp ,adjacentnode ,destination);
            }
        }
        
        visited[u] = false;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // mark all nodes as false
        for(int i =0 ;i<n;i++){
            visited[i] = false;
        } 
        vector <int> temp;
        dfs(graph ,temp ,0 ,n-1);
        return res ;
        
        
    }
};