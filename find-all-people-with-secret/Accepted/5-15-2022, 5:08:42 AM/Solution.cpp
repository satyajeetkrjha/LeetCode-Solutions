// https://leetcode.com/problems/find-all-people-with-secret

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      
        vector <vector <pair <int ,int>>> graph(n);
        int sz = meetings.size();
        for(int i =0 ;i< sz;i++){
            vector <int> vec = meetings[i];
            int u = vec[0];int v = vec[1];int t = vec[2];
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }
        
        
        priority_queue <pair <int ,int> ,vector <pair <int ,int> > ,greater<pair <int,int>>> q;
        // time and person
        q.push({0,firstPerson});
        q.push({0,0});
        vector <int> res ;
        vector <int> visited(n,false);
        while(!q.empty()){
            auto cur =q.top();
            q.pop();
            int person = cur.second ;
            int time = cur.first ;
            if(visited[person]){
                continue;
            }
            visited[person] = true ;
            for(auto it:graph[person]){
                int person = it.first ;
                if(!visited[person] && time <=it.second){
                    q.push({it.second ,person});
                }
            }
               
        }
        
        for(int i =0 ;i< n ;i++){
            if(visited[i]){
               res.push_back(i); 
            }
        }
        return res ;
        
    }
};