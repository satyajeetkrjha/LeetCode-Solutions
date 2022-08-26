// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack <int> st ;
       st.push(-1);
       int max_area = 0 ;
       for(int i =0 ;i<heights.size();i++){
           while(st.top() != -1 && heights[st.top()] >= heights[i]){
               int cur_height = heights[st.top()];
               st.pop();
               int current_width = i- st.top() -1;
               max_area = max(max_area ,cur_height*current_width);
           }
           st.push(i);
       }
        
       while(st.top() != -1){
           int current_height = heights[st.top()];
           st.pop();
           int current_width = heights.size() - st.top() -1;
           max_area = max(max_area ,current_height* current_width);
       } 
        return max_area ;
        
        
        
        
    }
};