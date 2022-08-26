// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack <int> st;
        int sz =T.size();
        vector <int> v(sz,0);
        for(int i = sz-1;i>=0;i--){
            while(!st.empty() && T[i]>=T[st.top()]){
                st.pop();
            }
            v[i] = (st.empty() ?0: st.top()-i);
            st.push(i);
        }
        return v;
    }
};