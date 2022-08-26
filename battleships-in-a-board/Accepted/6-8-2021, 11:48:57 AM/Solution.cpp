// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public:
    bool visited[200][200];
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    bool isValid(int a,int b,int r,int c){
        if(a >=0 && a<r && b>=0 && b<c){
            return true;
        }
        return false;
        
    }
    void dfs(vector<vector<char>>& board ,int i,int j ,int r,int c){
        if(!visited[i][j])
            visited[i][j]=true;
        
        for(int k=0;k<4;k++){
            int newx =i+dx[k];
            int newy =j+dy[k];
            if(isValid(newx,newy,r,c) && visited[newx][newy]== false && board[newx][newy] =='X'){
                dfs(board,newx,newy,r,c);
                    
            }
            
            
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int r= board.size();
        int c = board[0].size();
        
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++){
                visited[i][j]=false;
            }
        }
        int ans =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == 'X' && visited[i][j] == false){
                    dfs(board,i,j,r,c);
                    ans++;
                }
            }
        }
        return ans ;
        
    }
};