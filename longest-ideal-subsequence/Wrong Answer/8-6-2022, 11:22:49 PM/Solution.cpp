// https://leetcode.com/problems/longest-ideal-subsequence

class Solution {
public:
    int bucket[26];
    int count =0;
    
   
    
    int longestIdealString(string s, int k) {
     
        for(char a ='a';a<='z';a++){
          bucket[a-'a']= count;
          count++;
        }
        int maxwindow =0;
        int left =0 ;int right =1;
        while(left <=right && left>=0 && right <s.size()){   
            cout << s[right] << " "<< s[left]<<endl;
            cout << bucket[s[right]-'a'] << " "<< bucket[s[left]-'a'] <<endl;
            if((bucket[s[right]-'a']-bucket[s[left]-'a']) == k){
                maxwindow += max(maxwindow,right-left+1);
                right++ ;
                left++;
                continue ;
            }
            else{
                left++;
            }
            right++;
        }
        return maxwindow ;
    }
};