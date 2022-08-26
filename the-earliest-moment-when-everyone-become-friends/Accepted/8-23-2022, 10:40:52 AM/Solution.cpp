// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends

class Solution {
public:
    vector <int> parent ;
    int findparent(int u){
        while(u!=parent[u]){
            u = parent[u];
        }
        return u ;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        parent.resize(n+1);
        for(int i =0 ;i<n+1;i++)
            parent[i] = i ;
        
        for(int i =0 ;i<logs.size();i++){
            int u = logs[i][1];
            int v = logs[i][2];
            int p1 = findparent(u);
            int p2 = findparent(v);
            
            if(p1!=p2){
                n--;
                if(n == 1)
                    return logs[i][0];
                parent[p1] = p2;
            }
        }
        return -1;
    }
};