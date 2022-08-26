// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // so we store dist and index in priority queue
        
        priority_queue <pair <int ,int> > pq;
        
        for(int i =0 ;i< points.size();i++){
            
            int dist = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            if(pq.size() <k){
               pq.push({dist,i});           
            }
            else{
                auto cur = pq.top();
                if(cur.first > dist){
                    pq.pop();
                    pq.push({dist,i});
                }
            }
            
        }
        
        vector <vector <int> > res ;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            vector <int> temp = points[cur.second];
            res.push_back(temp);
        }
        return res ;
        
        
        
    }
};