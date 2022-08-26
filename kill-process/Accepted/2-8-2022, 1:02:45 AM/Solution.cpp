// https://leetcode.com/problems/kill-process

class Solution {
public:
    map <int ,vector <int>> parent ;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        for(int i=0 ;i<ppid.size();i++){
            int v = ppid[i];
            int u = pid[i];
            parent[v].push_back(u); 
        }
        
        queue <int> q ;
        q.push(kill);
        vector<int> res ;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                int node = q.front();
                q.pop();
                res.push_back(node);
                vector<int> children = parent[node];
                for(auto it :children){
                    q.push(it);
                }
            }
        }
        return res ;
        
        
        
    }
};