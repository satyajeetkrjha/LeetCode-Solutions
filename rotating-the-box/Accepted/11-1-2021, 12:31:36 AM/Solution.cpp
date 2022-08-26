// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int n = box.size(); // rows
        int m = box[0].size(); // columns
        
        vector <vector <char>> res(m,vector <char>(n,'.'));
        
        int k =0;
        for(int i =0 ;i<n;i++){
            for(int j = m-1,k = m-1;j>=0 ;j--){
                if(box[i][j] !='.'){
                 k= box[i][j] == '*' ? j : k;
                    res[k--][n-i-1] =box[i][j];
                }
            }   
        }
        return res ;
        
    }
};