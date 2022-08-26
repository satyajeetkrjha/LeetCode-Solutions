// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    bool visited[100];
    vector < vector <int> > res ;
    void dfs (vector <vector <int> > & graph ,int u ,int destination,vector <int> &temp){
        cout<<" u is "<<u <<endl;
       
        if(u == destination){
            temp.push_back(u);
            res.push_back(temp);
            return;  
        }
        visited[u] = true ;
        temp.push_back(u);
        for(int i =0 ;i< graph[u].size();i++){
            int adjacentnode = graph[u][i];
            cout<<"adjacent node is "<<adjacentnode <<endl;
            if(visited[adjacentnode] == false){
                dfs(graph,adjacentnode,destination,temp);
            }
        }
        visited[u] = false ;
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 0) return res ;
        for(int i =0 ;i<n+1 ;i++){
            visited[i] = false ;
        }
        vector <int> temp;
        dfs(graph,0 ,n-1 ,temp);
        return res ;
    }
};