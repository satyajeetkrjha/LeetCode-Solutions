// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    
    /*this stores 100 is at index 2 .Later when we find 100 at inndex 7 it gonna say 
     hey look we have 100 at indices 2 and 7 .Now when we start at index 2 ,we check the value at index 2 and we see that it's 100  so look for all indices had 100 as their value 
     */
    map <int ,vector <int >> m ; 
    int minJumps(vector<int>& arr) {
       int n = arr.size();
        for(int i=0 ;i< n;i++){
            m[arr[i]].push_back(i);
        }
        int visited[n+1];
        memset(visited,false,sizeof(visited));
        queue <int> q;
        int steps =0;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i< sz;i++){
                int index = q.front();
                q.pop();
                if(index == n-1){
                    return steps ;
                }
                int val = arr[index];
                vector <int> neighbouringindices = m[val];
                if(index -1 >=0 && !visited[index-1]){
                    neighbouringindices.push_back(index-1);
                }
                if(index+1 < n && !visited[index+1]){
                    neighbouringindices.push_back(index+1);
                }
                for(auto &it: neighbouringindices){
                    if(it>=0 && it<n && !visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
                
                neighbouringindices.clear();
                
            }
            steps++;
        }
        return steps ;
    }
    
};