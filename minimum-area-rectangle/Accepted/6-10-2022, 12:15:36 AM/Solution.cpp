// https://leetcode.com/problems/minimum-area-rectangle

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
       
        int n = points.size();
        int ans =INT_MAX ;
        map <int ,set<int>> m;
        
        for(int i =0 ;i< points.size();i++){
            vector <int> temp = points[i];
            m[temp[0]].insert(temp[1]);
        }
           
        
        
        for(int i =0 ;i<points.size()-1;i++){
            for(int j =i+1;j<points.size() ;j++){
             
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 == x2 || y1== y2)
                    continue ;
                
                if(m[x2].count(y1) ==1  && m[x1].count(y2) ==1 ){
                  ans = min(ans  ,abs(x1-x2)*abs(y1-y2));
                }
            }
        }
        return ans  == INT_MAX ? 0:ans;
            
    }
};