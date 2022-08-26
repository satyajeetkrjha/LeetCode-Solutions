// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

class Solution {
public:
    vector<int> adj[100005];
    int  dist1[100005];
    int  dist2[100005];
    map <int ,bool> visited1;
    map <int, bool> visited2;
    
    void dfs1(int u,int val){
        if(visited1[u] == true)
            return ;
        visited1[u] = true ;
        dist1[u] = val;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited1[v]){
                dfs1(v,val+1);
            }
        }
    }
    
    void dfs2(int u ,int val){
        if(visited2[u] == true){
            return;
        }
        visited2[u] = true;
        dist2[u] = val;
        for(int i =0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(visited2[v] == false){
                dfs2(v,val+1);
            }
        }
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        for(int i =0 ;i<edges.size();i++){
            if(edges[i] == -1)
                continue;
            else
            adj[i].push_back(edges[i]);
        }
        
       for(int i =0 ;i<edges.size();i++){
           dist1[i]= dist2[i] = -1;
       }
      
        dfs1(node1,0);
        dfs2(node2,0);
        
        
        
        

       
    
        int mindist=INT_MAX;
        map <int,vector<int>> nodes;
        for(int i = 0 ;i<edges.size();i++){
            if(dist1[i] == -1 || dist2[i] == -1)
                continue;
            else{
                
                int val = max(dist1[i],dist2[i]);
                nodes[val].push_back(i);
                mindist = min(mindist,max(dist1[i],dist2[i]));
            }      
        }
        
        
        if(mindist == INT_MAX)
            return -1;
        return nodes[mindist][0] ;
    }
};