// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int count =0;
      int i=0;
      while(i<flowerbed.size()){
          if( i ==0 && flowerbed[i] ==0 && flowerbed[i+1] ==0){
              flowerbed[i]=1;
              count++;
            
          }
          else if(i == flowerbed.size()-1 && flowerbed[i]==1 && flowerbed[i-1]==0){
              flowerbed[i]=1;
              count++;
             
          }
          else if(i!=0 && i!=flowerbed.size()-1 ;flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
              flowerbed[i]=1;
              count++;
          }
          i++;
          
      }
        return count >=n;
        
        
        
    }
};