// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
       // cout<<"rows "<<rows<<endl;
        
        for(int i=0;i<rows;i++){
            int val = image[0].size();
           // cout<<"rows[0] is"<<val<<endl;
           int mid =(image[0].size()+1)/2;
           // cout<<"mid is "<<mid<<endl;
           for(int j=0;j<mid;j++){
               int temp =image[i][j];
               image[i][j] =!image[i][mid-j];
               image[i][mid-j] =!temp;
           } 
        }
        return image;
    }
};