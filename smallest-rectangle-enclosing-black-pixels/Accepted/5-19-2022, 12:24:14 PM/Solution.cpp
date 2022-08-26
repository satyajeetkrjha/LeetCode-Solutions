// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

class Solution {
public:
    int minX ,minY ,maxX,maxY ;
 
    
    void dfs (vector<vector<char>>& image ,int x ,int y){
        if( x >= image.size() || x <0 || y >= image[0].size() || y < 0 || image[x][y] == '0')
            return ;
        
        image[x][y] ='0';
        
        minX = min(minX,x);
        minY= min(minY,y);
        maxX = max(maxX,x);
        maxY = max(maxY,y);
        
        dfs(image ,x+1,y);
        dfs(image ,x-1,y);
        dfs(image,x,y+1);
        dfs(image ,x,y-1);
        
        
    }
    
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        /* x and y is one of the black pixel of the only connected component*/
         minX=image.size() -1;
         maxX=0;
         minY =image[0].size()-1;
         maxY= 0;
         dfs(image ,x,y);
         return (maxX-minX+1)*(maxY-minY+1);
        
        
        
    }
};