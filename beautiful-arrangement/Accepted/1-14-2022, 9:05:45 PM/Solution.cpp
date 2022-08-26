// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int count =0;
    int countArrangement(int n) {
        vector <bool> visited(n+1,false);
        backtrack(1,n,visited);
        return count ;
    }
    void backtrack(int pos ,int N,vector<bool> visited){
        if(pos>N){
            count++;
        }
        for(int i =1 ;i<=N;i++){
            if(!visited[i] && (pos %i ==0 || i%pos == 0)){
                visited[i]=true;
                backtrack(pos+1,N,visited);
                visited[i] =false;
            }
            
        }
    }
};