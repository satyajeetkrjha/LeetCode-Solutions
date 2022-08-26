// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       
        int n = temperatures.size();
        stack <pair <int ,int> > st;
       
        vector <int> res;
        res.resize(n,0);
        for(int i = n-1 ;i>=0 ;i--){
            
            while(!st.empty() && temperatures[i] >= st.top().first){
                st.pop();
            }
            
            res[i] = st.empty() ? 0 : st.top().second - i;
            st.push({temperatures[i],i});
        }
        return res ;
        
    }
};