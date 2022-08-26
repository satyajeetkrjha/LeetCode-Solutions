// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    // void printvector(vector<int> v){
    //     for(int i=0;i<v.size();i++){
    //         cout<<v[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        
       int totalRows =matrix.size();
       int totalCols=matrix[0].size();
        if(totalRows ==0 && totalCols==0)
            return ans;
        int top=0;int bottom =totalRows-1;
        int left =0;int right =totalCols-1;
        int dir =0;
        while(top<=bottom && left<=right){
            if(dir ==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);   
                }
               // printvector(ans);
                top++;
            }
            else if(dir == 1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                    
                }
               // printvector(ans);
                right--;
                
            }
            else if(dir ==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                    
                }
               // printvector(ans);
                bottom--;
            }
            else if(dir ==3){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                   
                }
               // printvector(ans);
                 left++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};