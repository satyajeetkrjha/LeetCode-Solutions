// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    map<string ,priority_queue<string ,vector<string>,greater<string>>> m;
    vector <string> res ;
    void dfs(string s){
        while(m[s].size() >0){
            auto nextnode = m[s].top();
            m[s].pop();
            dfs(nextnode);
        }
        res.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(int i =0 ;i<tickets.size();i++){
            string u = tickets[i][0];string v = tickets[i][1];
            m[u].push(v);
        }
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res ;
    }
};