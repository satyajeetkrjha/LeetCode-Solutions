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
        int row  = dimension[0];
        int column = dimension[1];
        
        int currentrow = 0 ;
        int currentcolumn = column -1;
        while(currentrow <row &&  currentcolumn >=0){
            if(binaryMatrix.get(currentrow,currentcolumn) ==0){
                currentrow++;
            }
            else {
                currentcolumn --;
            }
        }
        if(currentcolumn == column-1){
            return -1;
        }
        return currentcolumn+1;
    }
};