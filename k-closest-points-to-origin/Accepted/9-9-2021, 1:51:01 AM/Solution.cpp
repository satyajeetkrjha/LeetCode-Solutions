// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue <pair <int ,int> > pq ; // max heap storing dist and index
      
        vector <vector <int> > res;
        for(int i =0 ;i<points.size();i++){
             vector <int> v = points[i];
            int dist = (v[0]*v[0])+v[1]*v[1];
            if(pq.size() <k){
                pq.push({dist,i});
            }
            else {
                pair <int,int> val = pq.top();
                if(val.first>dist){
                    pq.pop();
                    pq.push({dist,i});
                }
               // do nothing otherwise                
            }
        }
        
        while(pq.size()!=0){
           pair <int ,int> val = pq.top();
            pq.pop();
            int index = val.second ;
            res.push_back(points[index]);
        }
        return res ;
        
    }
};