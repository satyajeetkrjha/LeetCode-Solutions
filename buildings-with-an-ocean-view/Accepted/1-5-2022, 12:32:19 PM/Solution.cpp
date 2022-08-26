// https://leetcode.com/problems/buildings-with-an-ocean-view

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack <int> s;
        int n = heights.size();
        s.push(n-1);
        vector <int> res ;
        int maxheight = heights[n-1];
        for(int i = n-2;i>=0 ;i--){
            if(heights[i] > maxheight){
                s.push(i);
            }
            maxheight = max(maxheight,heights[i]);
        }
        
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res ;
    }
};