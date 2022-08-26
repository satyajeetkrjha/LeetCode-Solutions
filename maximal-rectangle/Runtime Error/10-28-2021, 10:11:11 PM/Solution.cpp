// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int histogram( vector <int> heights){
        
        /*
        cout<<"Printing heights "<<endl;
        for(int i =0 ;i<heights.size();i++){
            cout <<heights[i] << " ";
        }
        cout <<endl;
        cout <<"End of printing heihts "<< endl;
        */
        stack <int> st ;
        st.push(-1);
        int maxarea =0 ;
        for(int i =0 ;i<heights.size();i++){
            while(st.top()!= -1 && heights[st.top()] >= heights[i]){
                int cur_height = heights[st.top()];
                st.pop();
                int cur_width = i - st.top() -1;
                maxarea = max(maxarea ,cur_height*cur_width);
            }
            st.push(i);
        }
        
        while(st.top() !=-1){
            int cur_height = heights[st.top()];
            st.pop();
            int cur_width = heights.size() - st.top() -1 ;
            maxarea = max(maxarea ,cur_height*cur_width);
        }
        return maxarea ;
    }
    

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size() ;
        int c = matrix[0].size() ;
        vector <int> dp;
        dp.resize(c+1);
        for(int i =0 ;i<dp.size();i++){
            dp[i] =0;
        }
        int maxarea =0;
        for(int i =0 ;i<r;i++){
            for(int j =0;j<c;j++){
                dp[j] = matrix[i][j] == '1' ? dp[j]+1 :0;
            }
            maxarea = max(maxarea ,histogram(dp));
            //cout <<"maxarea is "<< maxarea <<endl;
        }
        return maxarea ;
        
    }
};