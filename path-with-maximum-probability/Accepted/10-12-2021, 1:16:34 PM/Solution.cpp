// https://leetcode.com/problems/path-with-maximum-probability

#include <iomanip>
typedef pair <double ,int> pr ;
double dist[100005];
class Solution {
public:
    
    void dijkistra(vector<vector <pair<int,double>>> &graph,int start ,int end){
        priority_queue <pr> pq;
        pq.push({1,start});
        memset(dist,INT_MIN,sizeof(dist));
        dist[start]=1;
        while(!pq.empty()){
            pr cur = pq.top();
            pq.pop();
            double w = cur.first ;
            int u = cur.second;
            for(auto nei:graph[u]){
                int v = nei.first;
                double d = nei.second;
                //cout<<"d is "<<d <<endl;
                if(dist[v]<d*w){
                    dist[v] = d*w;
                    pq.push({dist[v],v});
                }
            }
        }
        
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector <pair<int,double>>> graph ;
        graph.resize(n);
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0];int v = edges[i][1];double w = succProb[i];
            //cout<<" u v and w are "<<u << " "<< v<< " "<<w<<endl;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
            
        }
         dijkistra(graph,start,end);
        if(dist[end] == INT_MAX){
            return 0.00000;
        }
        else{
            return dist[end];
        }
        
    }
};