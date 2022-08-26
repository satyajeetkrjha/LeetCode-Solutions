// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    vector <int> adj[100005];
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<manager.size();i++){
            if(manager[i] == -1)
                continue;
            adj[manager[i]].push_back(i);
        }
        queue <pair <int,int>> q;
        q.push({headID,0});
        int finishTime =0;
        int cur_time =INT_MIN;
        while(!q.empty()){
            pair <int,int> val = q.front();
            q.pop();
            int node =  val.first;
            int time = val.second+informTime[node];
            finishTime =max(finishTime,time);
            for(int i=0;i<adj[node].size();i++){
                int v = adj[node][i];
                q.push({v,time});
            }
        }
        return finishTime ;
    }
};