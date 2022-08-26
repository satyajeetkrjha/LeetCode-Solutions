// https://leetcode.com/problems/flood-fill

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int oldColor, int newColor,int rows,int columns){
        if(sr <0 || sr>=rows || sc<0 || sc>=columns || image[sr][sc]!=oldColor)
            return;
        image[sr][sc]=newColor;
        dfs(image,sr+1,sc,oldColor,newColor,rows,columns);
        dfs(image,sr-1,sc,oldColor,newColor,rows,columns);
        dfs(image,sr,sc+1,oldColor,newColor,rows,columns);
        dfs(image,sr,sc-1,oldColor,newColor,rows,columns);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows =image.size();
        if(rows ==0)
            return image;
        int columns =image[0].size();
        int oldColor =image[sr][sc];
        if(oldColor != newColor){
            dfs(image ,sr,sc,oldColor,newColor,rows,columns);
            return image;
        }
        else
            return image;
    }
};