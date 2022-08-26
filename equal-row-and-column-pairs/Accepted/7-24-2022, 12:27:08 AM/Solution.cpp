// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      map <int ,vector <int> > rows ;
      map <int ,vector <int> >columns ;
        vector <int> temp1 ,temp2;
      for(int i =0 ;i <n;i++) {
          for(int j =0 ;j<m;j++){
              temp1.push_back(grid[j][i]);
              temp2.push_back(grid[i][j]);
          }
        
          columns[i]=temp1;
          rows[i]=temp2;
          temp1.clear();temp2.clear();

      }
        
       
        int count =0;
      for(int i =0 ;i< n;i++){
          vector <int> temp = rows[i];
          for(int j =0 ;j<n;j++){
              vector <int> temp1 = columns[j];
              if(temp == temp1){
                  count ++;
              }
          }
      }
        return count ;
        
        
    }
};