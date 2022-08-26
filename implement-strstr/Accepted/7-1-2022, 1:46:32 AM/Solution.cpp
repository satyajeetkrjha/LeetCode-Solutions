// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    vector <int> lps ;
    
    void computelps(string pattern ,vector <int> &lps){
        lps[0] =0 ;
        int len =0;
        int i =1;
        while(i < pattern.size()){
            if(pattern[i] == pattern[len]){
                lps[i] = len+1;
                i++;
                len++;
            }
            else{
                if(len !=0)
                    len = lps[len-1];
                else{
                    lps[i] =0 ;
                     i++;
                }     
            }
        }
      }
    
    int strStr(string text, string pattern) {
        int n = text.size();
        int m = pattern.size() ;
        lps.resize(m,0);
        computelps(pattern,lps);
        int i =0 ;int j =0 ;
        while(i< n){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
            
            if( j == m){
                return i-j;
            }
        }
        return -1;
        
    }
};