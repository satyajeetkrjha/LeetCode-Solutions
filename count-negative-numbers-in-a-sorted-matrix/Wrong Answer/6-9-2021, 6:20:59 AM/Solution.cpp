// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int totalnegative =0;
        int lastnegative = grid[0].size()-1 ;
        int rows = grid.size();
        int col = grid[0].size(); // this will remain constant and we will use this to subtract later
        int high ;
        int low =0;
        for(int i=0;i<rows;i++){
            if (grid[i][col-1]>0){ // last element of this column is positive so just move to next row
                continue;   
            }
            
            if(grid[i][0]<0){
                totalnegative+=col; // all elements in. that row is negative
                continue;
            }
            
            // now do a binary search to find first occurence of negative 
            high = lastnegative ; // this will reduce serach space for next row
            cout<<"low is "<<low <<endl;
            cout<<"high is "<<high <<endl;
            cout<<"totalnegative is "<<totalnegative <<endl;
            while(low <=high){
                
                int mid =(low+high)/2;
                cout<<"low is "<<low<<endl;
                cout<<"mid is "<<mid<<endl;
                cout<<"grid["<<i<<" "<<mid<<"] "<<grid[i][mid]<<endl;
                if(grid[i][mid]<0){
                    lastnegative = mid ;
                    high =mid-1;
                    cout <<"lastnegative is "<<lastnegative <<endl;
                }
                else if (grid[i][mid]>=0){
                    low =mid+1;
                }
            }
            cout<<"last negative is "<<lastnegative <<endl;
            cout<<"col is "<<col<<endl;
            cout<<"last negative is "<<lastnegative <<endl;
            cout<<"totalneative before adding is "<<totalnegative <<endl;
            int diff = col-lastnegative ;
            cout<<"diff is "<<diff <<endl;
            totalnegative = totalnegative +diff;
            
           
            cout<<"totalnegative is "<<totalnegative <<endl;
            low =0;
          }
        return totalnegative;
        }

};