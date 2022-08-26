// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    priority_queue<pair<int,int> > pq ;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i =0 ;i<points.size();i++){
            int x = points[i][0];int y = points[i][1];
            int dist = x*x+ y*y;
            pq.push({dist,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
    
        vector <vector <int> > res ;
        for(int i =0 ;i < k;i++){
            auto cur = pq.top();
            pq.pop();
            res.push_back(points[cur.second]);
        }
        
        return res ;
        
    }
};