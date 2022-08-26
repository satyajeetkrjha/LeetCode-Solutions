// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    bool visited[105];
    vector <vector <int> > res ;
    void printtemp(vector <int> temp){
        for(int i =0 ;i<temp.size();i++){
           cout<<temp[i]<< " "; 
        }
        cout<<endl;
    
    }
    
    void dfs(vector<vector<int>>& graph, vector <int> temp ,int u ,int destination){
        //cout<<"u and destination are ... "<<u <<  "   "<<destination <<endl;
        if(u == destination){
            temp.push_back(u);
          //  cout<<"Temp after destination match .."<<endl;
            //printtemp(temp);
            res.push_back(temp);
            temp.pop_back();
            return ;
        }
        
        
            
        
        temp.push_back(u);
      //  cout<<"temp now is "<<endl;
        //printtemp(temp);
        for(int i =0 ;i<graph[u].size();i++){
            int adjacentnode = graph[u][i];
            //cout<<"adjacent node is "<<adjacentnode<<endl;
                dfs(graph ,temp ,adjacentnode ,destination);
            
        }
        temp.pop_back();
       
        //cout<<"node "<< u << " visited false"<<endl;
        
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