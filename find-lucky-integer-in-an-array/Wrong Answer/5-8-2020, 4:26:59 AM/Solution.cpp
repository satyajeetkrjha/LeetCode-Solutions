// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
      int n = arr.size();
      map <int ,int> m;
      for(int i=0;i<n;i++){
          m[arr[i]]++;
      }
       int largest =-100000;
     for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
         if (it->first == it->second){
            largest =max(largest,it->first);
         }
     }
       

  return largest;
}
        
    
};