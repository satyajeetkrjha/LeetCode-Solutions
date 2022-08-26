// https://leetcode.com/problems/word-search

class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int i,int j, string cur,int index, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i> board.size() || j>board[0].size() || visited[i][j] || board[i][j]!=word[index] || index> word.length()){
            return false;
        }
        if(board[i][j] == word[index]){
            cur+=word[index];
            index++;
            visited[i][j]=true;
        }
        if(dfs(board,word,i+1,j,cur,index,visited) || dfs(board,word,i,j+1,cur,index,visited) || dfs(board,word,i-1,j,cur,index,visited) ||
           dfs(board,word,i,j-1,cur,index,visited)
          )
            return true;
        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows =board.size();
        int columns =board[0].size();
         
        vector <vector<bool>>visited(rows,vector<bool>(columns,false));
        bool ans =false;
        for(int i=0;i<rows;i++){
               string cur="";
            for(int j=0;j<columns;j++){
                if(board[i][j] == word[0]){
                    ans= dfs(board,word,i,j,cur,0,visited);
                }
                if(ans){
                    ans=true;
                    break;
                }
            }
            if(ans){
                ans=true;
                break;
            }
        }
        return ans;
        
        
        
    }
};