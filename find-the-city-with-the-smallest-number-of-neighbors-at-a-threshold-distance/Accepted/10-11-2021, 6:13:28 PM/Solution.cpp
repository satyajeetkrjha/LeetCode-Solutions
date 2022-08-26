// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

typedef pair <int,int> pr;
int threshold;
int dist[100005];
int seen[100005];
class Solution {
public:
    int dijkistra(vector<vector<pair<int, int>>>& graph,int start,int nodes){
       // cout<<"nodes "<<nodes <<endl;
       priority_queue<pr ,vector <pr>,greater<pr>> pq;
        
        
       pq.push({0,start}); // weight and node
       for(int i =0 ;i<=nodes ;i++){
           dist[i] =INT_MAX;
           seen[i]= 0;
       }
       dist[start] =0 ;
       while(!pq.empty()){
           pr curr = pq.top();
           pq.pop();
           int w = curr.first ; // weight
           int u = curr.second; // node
           
            for(auto& nei :graph[u]){
                int v = nei.first ;
                int d = nei.second;
               // cout<<"v are "<<v <<endl;
                int cost = d+w;
                if(dist[v]> cost){
                    dist[v] = cost;
                    pq.push({dist[v],v});
                }
            } 
       }
        /*
        cout <<"calculating distance "<<endl;
        for(int i =0 ;i<nodes ;i++){
            cout<<"dist[i] "<< dist[i]<< " ";
        }
        cout<<endl;*/
        int count =0 ;
        for(int u =0 ;u <nodes ;u++){
            if( u == start){
                continue;
            }
            if(dist[u]<= threshold){
                count ++;
            }
        }
        //cout <<"count is "<<count <<endl;
        return count ;
       
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<pair<int, int>>>graph;
        graph.resize(n);
        threshold = distanceThreshold;
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0];int v = edges[i][1];int w = edges[i][2];
           // cout <<"u v and w are "<< u << " "<< v<< " "<<w <<endl;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        /*
        cout<<"Printing graph "<<endl;
        for (int u = 0;u <n;u++) {
		for (auto it : graph[u]) {
			int v = it.first;
			int w = it.second;
			//cout << " u is " << u << " v is " << v << " and w is " << w << endl;
		}
	  }
	cout<< "---------"<<endl;
    */

        
        
        int neighbours =INT_MAX;
        int nodeVal = -1;
        for(int i =0 ;i<n;i++){
           int totalneighbours = dijkistra(graph,i,n);
           cout <<"totalneighbours .."<<totalneighbours <<endl;
            cout<<"nodeval is "<<nodeVal <<endl;
            if(totalneighbours <=neighbours){
                neighbours = totalneighbours ;
                nodeVal = i;
            }
        }
        return nodeVal;
        
    }
};