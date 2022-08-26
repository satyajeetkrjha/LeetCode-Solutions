// https://leetcode.com/problems/leftmost-column-with-at-least-a-one

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector <int> dimension = binaryMatrix.dimensions();
      int row = dimension[0];
      int column = dimension[1];
        cout<<"row and column "<<row << " "<<column <<endl;
      int smallestindex = column;
      for(int i  =0;i<row;i++){
          int low =0;
          int high = column-1;
          while(low <high){
              int mid =(low+high)/2;
              if(binaryMatrix.get(i,mid) == 0){
                  low =mid+1;
              }
              else {
                  high = mid;
              }
          }
          cout<<"low is "<<low<<endl;
          cout<<"high is "<<high<<endl;
          if(binaryMatrix.get(i,low) == 1){
              smallestindex = min(smallestindex ,low);
          }
      }
        if(smallestindex == column){
            return -1;
        }
        return smallestindex ;
    }
};