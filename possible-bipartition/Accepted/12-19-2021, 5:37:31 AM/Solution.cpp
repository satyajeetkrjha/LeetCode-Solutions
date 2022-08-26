// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector <int> sides(n+4,-1);
        queue <int> q;
        bool isbipartite = false;
        
        vector <int> adj[n+5];
        for(int i =0 ;i<dislikes.size();i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);  
        }
        
        
        for(int i = 1;i<=n;i++){
            if(sides[i] == -1){
                q.push(i);
                sides[i] = 0 ;  
                while(!q.empty()){
                    int u  = q.front();
                    q.pop();
                    cout <<" u is "<< u <<endl;
                    cout <<"color of u is "<< sides[u]<<endl;
                    cout <<" size is "<< adj[u].size()<<endl;
                    for(auto v:adj[u]){
                        cout <<"v is ...."<< v <<endl;
                        if(sides[v] == -1){
                            sides[v] = sides[u]^1;
                            q.push(v);
                        }
                        else{
                           if(sides[u] == sides[v]){
                               return false;
                           }
                        }
                    }
                }
            }
        }
        return true ;
        
    }
};