// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q ;
        q.push(start);
        
        int n = arr.size();
        
        while(!q.empty()){
            int index = q.front();
            q.pop();
            
            if(arr[index] ==0)
                return true;
            
            // cout<<"index is "<<index<<endl;
            
            int node1 = arr[index]+ index ;
            int node2 = index -arr[index] ;
            
            // cout<<"neighbour node1 is "<<node1 <<endl;
            // cout<<"neighbour node2 is "<<node2 <<endl;
            
            if(node1 >=0 && node1 <n){
                if(arr[node1] ==0)
                    return true;
                else{
                    q.push(node1);
                }
            }
            if(node2 >=0 && node2 <n){
                if(arr[node2] ==0)
                    return true;
                else{
                    q.push(node2);
                }
            }
                
        
        }
        return false ;
        
    }
};