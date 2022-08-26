// https://leetcode.com/problems/add-binary

class Solution {
public:
    string res ="";
    string addBinary(string a, string b) {
      int n = a.size()-1;
      int m = b.size()-1;
      int carry =0;
      while( n>= 0 || m>=0 || carry ==1){
          if(n>=0 && a[n] =='1') carry++;
          if(m>=0 && b[m] =='1') carry++;
          res= (carry%2 ==0 ?'0':'1')+res;
          carry = carry/2;
          n-- ;m--;
          
      }
        
        return res ;
        
        
    }
};