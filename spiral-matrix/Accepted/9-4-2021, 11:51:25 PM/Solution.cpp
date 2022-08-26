// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    void printSolution(vector <int> ans){
        for(int i =0 ;i<ans.size();i++){
          cout<<ans[i]<< " ";   
        }
        cout <<endl;
       
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int top = 0 ;int bottom = r-1;
        int left = 0 ;int right = c-1;
        
        int dir = 0 ;
        
        vector <int> ans ;
        
        
        cout<<"top is "<<top<<endl;
        cout<<"left is "<<left <<endl;
        cout << "bottom is "<<bottom <<endl;
        cout <<"right is "<<right<<endl;
        
        
        while( top <= bottom && left <= right){
            
            if(dir == 0){
                for(int i = left ;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                 printSolution(ans);
                top++;
            }
            else if( dir  == 1){
                cout<<"top and bottom is "<<top << " "<<bottom <<endl;
                for(int i = top ;i <= bottom ;i++){
                    cout <<"right and i are"<<right <<" "<<i <<endl;
                    ans.push_back(matrix[i][right]);
                }
                printSolution(ans);
                right --;
            }
            else if ( dir == 2){
                for(int i = right ;i>= left ;i--){
                    ans.push_back(matrix[bottom][i]);
                    cout <<"bottom and i are "<<bottom <<" "<<i <<endl;
                }
                 bottom --;
            }
            else if ( dir == 3){
                cout<<"bottom and top are  "<<bottom <<" "<<top <<endl;
                for(int i = bottom ;i>= top ;i--){
                    ans.push_back(matrix[i][left]);
                    cout <<"left and i are "<< left << " "<< i << endl;
    
                }
                 left++;
            }
            dir = ( dir+1)%4;
            
        }
        return ans ;
    }
};