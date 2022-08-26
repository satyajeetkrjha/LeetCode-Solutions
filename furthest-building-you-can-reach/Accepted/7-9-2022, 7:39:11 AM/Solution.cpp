// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue <int> pq ; // max heap
        int diff = 0 ;
        int n = heights.size();
        int i ;
        for(i =0 ;i< n-1 ;i++){
            diff = heights[i+1] - heights[i];
            pq.push(diff);
            if(diff >0){
                bricks -= diff ;
                if(bricks<0){
                    if(ladders <=0 ) return i ;
                    int bricksrestored = pq.top();
                    pq.pop();
                    bricks+= bricksrestored ;
                    ladders --;
                }
                
            }
        }
        return i ;    
    }
};