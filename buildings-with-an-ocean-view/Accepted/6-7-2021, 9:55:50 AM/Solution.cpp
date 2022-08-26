// https://leetcode.com/problems/buildings-with-an-ocean-view

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
      vector <int> ans ;
        int n = heights.size();
        if(n ==0)
            return ans ;
        int maxHeight = heights[n-1];
        stack <int> s;
        s.push(n-1);
        for(int i =n-2;i>=0;i--){
            if(heights[i]>maxHeight){
                s.push(i);
            }
            maxHeight =max(maxHeight,heights[i]);

        }
        while(!s.empty()){
            int val =s.top();
            s.pop();
            ans.push_back(val);
        }
        return ans ;
    }
};