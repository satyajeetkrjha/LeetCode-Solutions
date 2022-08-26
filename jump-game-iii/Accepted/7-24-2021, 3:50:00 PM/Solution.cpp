// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q ;
        q.push(start);
        
        int n = arr.size();
        bool visited [n+1];
        memset(visited ,false ,sizeof(visited));
        
        while(!q.empty()){
            int index = q.front();
            q.pop();
            
            if(arr[index] ==0)
                return true;
            
            visited [index]= true;
            
            // cout<<"index is "<<index<<endl;
            
            int node1 = arr[index]+ index ;
            int node2 = index -arr[index] ;
            
            // cout<<"neighbour node1 is "<<node1 <<endl;
            // cout<<"neighbour node2 is "<<node2 <<endl;
            
            if(node1 >=0 && node1 <n){
                if(arr[node1] ==0 )
                    return true;
                else if(!visited[node1]){
                    q.push(node1);
                    visited[node1]=true;
                }
            }
            if(node2 >=0 && node2 <n){
                if(arr[node2] ==0)
                    return true;
                else if(!visited[node2]){
                    q.push(node2);
                    visited[node2]=true;
                }
            }
                
        
        }
        return false ;
        
    }
};