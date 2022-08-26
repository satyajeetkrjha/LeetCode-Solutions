// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair <int,int> > pq; // dist and index
        // this is max heap so the top most element will be the largest
        
        vector <vector <int> > res; // this contains the answer
        
        for(int i=0;i<points.size();i++){
            vector <int> v = points[i];
            int dist = (v[0]*v[0])+(v[1]*v[1]);
            if(pq.size()<k){
                pq.push(make_pair(dist,i));
            }
            else {
                if(pq.top().first>dist){
                    pq.pop();
                    pq.push(make_pair(dist,i));
                }
            }
        }
        
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            vector <int> vec = points[index];
            res.push_back(vec);
        }
        return res ;
        
    }
};