// https://leetcode.com/problems/tree-diameter

class Solution {
public:
    vector <int> adj[100005];
    int treeDiameter(vector<vector<int>>& edges) {
        
        int startnode ;
        for(auto edge: edges){
            int u = edge[0];int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            startnode = u;
        }
        
        // now do a bfs from this startnode to find first peripheral node 
        int dist [edges.size()+2];
        int visited[edges.size()+2];
        memset(visited,0,sizeof(visited));
        
        queue<int> q1;
        q1.push(startnode);
        visited[startnode]= 1;
        int farthestnode =0;
        while(!q1.empty()){
            int u =q1.front();
            q1.pop();
            for(int i =0 ;i<adj[u].size();i++){
                int v = adj[u][i];
                if(!visited[v]){
                    visited[v] = 1;
                     q1.push(v);
                }
            }
           // cout<<"q1 size is "<< q1.size()<< endl;
            if(q1.size() ==1){
                farthestnode = q1.front();
            }
        }
        
        cout <<"farthest node is "<< farthestnode << endl;
        
        
        memset(dist,INT_MAX,sizeof(dist));
        memset(visited,0,sizeof(visited));
        queue<int> q2 ;
        q2.push(farthestnode);
        dist[farthestnode] = 0;
        visited[farthestnode] =1 ;
        
        //cout <<"Second bfs"<< endl;
        while(!q2.empty()){
            int u = q2.front();
            q2.pop();
            cout <<" u is "<< u << endl;
            for(int i =0 ;i<adj[u].size();i++){
                int v = adj[u][i];
                if(!visited[v]){
                    cout <<"v is "<< v <<endl;
                    dist[v] = dist[u]+1;
                    visited[v] =1 ;
                    q2.push(v);
                }
            }
        }
       // cout <<" before comparasion ...."<< endl;
        int ans =0;
        for(int i =0 ;i<= edges.size();i++){
          //  cout <<" dist["<< i<<" ] "<< dist[i]<<endl;
            ans = max(ans ,dist[i]);
        }
       // cout <<"ans is "<< ans << endl;
        return ans ;
        
    
                  
        
        
        
    }
};