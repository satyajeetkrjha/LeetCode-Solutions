// https://leetcode.com/problems/buildings-with-an-ocean-view

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        int n = heights.size();
        stack <int> st ;
        int leftmax = heights[n-1];
        st.push(n-1);
    
        for(int i = n-2;i>=0 ;i--){
            if(heights[i] > leftmax){
                st.push(i);
            }
            leftmax= max(leftmax,heights[i]);
            
        }
        
        vector <int>  res ;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res ;
        
        
        
        
        
        
        
    }
};