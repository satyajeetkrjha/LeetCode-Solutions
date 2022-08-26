// https://leetcode.com/problems/kill-process

class Solution {
public:
    map <int ,vector <int> > m;
    vector <int> res ;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for(int i =0 ;i<pid.size();i++){
            int u = pid[i];int v = ppid[i];
               m[v].push_back(u);
            }
        
        
        queue <int> q ;
        q.push(kill);
        
       
        
        
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                res.push_back(cur);
                for(auto &child:m[cur]){
                    q.push(child);
                }
            }
        }
        return res ;
        
    }
};