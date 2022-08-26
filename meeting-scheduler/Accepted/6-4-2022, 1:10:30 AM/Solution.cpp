// https://leetcode.com/problems/meeting-scheduler

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        vector <int> res ;
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        
        int i =0 ;int j =0;
        while(i< slots1.size() && j <slots2.size()){
            int intersectionstart = max(slots1[i][0],slots2[j][0]);
            int intersectionend = min(slots1[i][1],slots2[j][1]);
            if(intersectionstart+duration <=intersectionend){
                res.push_back(intersectionstart);
                res.push_back(intersectionstart+duration);
                return res;
            }
            if(slots1[i][1] <slots2[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        
            return res ;
            
            
            
        
    }
};