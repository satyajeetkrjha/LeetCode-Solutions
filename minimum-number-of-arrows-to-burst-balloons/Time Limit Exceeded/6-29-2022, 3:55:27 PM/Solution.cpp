// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    
   // sort on basis of end time 
   static bool compare(const vector <int> p1 ,const vector <int> p2){
       return p1[1] < p2[1] ;
   }
    
    
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int sz = points.size();
        
        sort (points.begin(),points.end(),compare);
        int oldstart = points[0][0];
        int oldend = points[0][1];
        
        int arrows =1 ;
        for(int i = 1 ;i< sz;i++){
            int newstart = points[i][0];
            int newend = points[i][1];
            
            if(newstart > oldend){
                arrows++ ;
                oldend = newend ;
            }
        }
        return arrows ;
    }
};