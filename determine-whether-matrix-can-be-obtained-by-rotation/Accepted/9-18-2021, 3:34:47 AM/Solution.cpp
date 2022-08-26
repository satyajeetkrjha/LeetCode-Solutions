// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool matrixequality(vector<vector<int>>& a, vector<vector<int>>& b){
        for(int i =0 ;i<a.size();i++){
            for(int j =0 ;j<a[0].size();j++){
                if(a[i][j]!= b[i][j])
                    return false;
            }
        }
        return true;
    }
    void rotatematrix(vector<vector<int>>& mat){
        // transposed first 
        int n = mat.size();int m = mat[0].size();
        for(int i =0 ;i<n;i++){
            for(int j = i ;j<m;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        cout<<"transposed ..."<<endl;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                cout <<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        
        // now reverse it 
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m/2;j++){
               swap(mat[i][j],mat[i][m-j-1]);
            }
        }
        cout<<"reversed..."<<endl;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                cout<<mat[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        // first case can be there is no rotation at all 
      if(mat.size() == target.size() && mat[0].size() == target[0].size()){
          if(matrixequality(mat,target)){
              return true;
          }
            // let's rotate it one by 90 ,180 and 270 degress and then see equality 
            cout<<"else part callled "<<endl;
            for(int i =0 ;i<3;i++){
                cout<<"called"<<endl;
                rotatematrix(mat);
                if(matrixequality(mat,target)){
                    return true;
                }
            }
    }
       return false;  
    }
};