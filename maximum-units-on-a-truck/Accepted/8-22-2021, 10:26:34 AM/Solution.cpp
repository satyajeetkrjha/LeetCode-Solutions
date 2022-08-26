// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    
    struct comparator{
        bool operator()(vector <int> const &p1,vector <int> const &p2){
            return p1[1]> p2[1];
        }
    };
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(),boxTypes.end(),comparator());    
      int availabletrucksize = truckSize;
      int sum =0 ;
      for(int i =0 ;i<boxTypes.size();i++){
          if(availabletrucksize == 0) break;
          vector <int> v = boxTypes[i];
          int num =v[0];int weight = v[1];
          sum += min(num,availabletrucksize)*weight;
          availabletrucksize-= min(num,availabletrucksize);
          
      }
        return sum ;
        
        
        
        
        
    }
};