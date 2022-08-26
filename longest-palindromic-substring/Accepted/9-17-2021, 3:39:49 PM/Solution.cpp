// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int expandaroundcenters(string s, int left ,int right){
        while(left >=0 && right <s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        
        /*
        we are basically considering every single character and every two characters as a possible centers of palinfromic substring and expanding around it
        */
        int len = 0 ;
        int start =0 ;int end =0;
        int maxlen =0;
        for(int i =0 ;i<s.size();i++){
            int len1 = expandaroundcenters(s,i,i);
            int len2 = expandaroundcenters(s,i ,i+1);
            //cout<<len1<< " "<<len2<<endl;
            // find the largest of the two
            int len = max(len1,len2);
            if(len > end - start){
                maxlen = max(len ,maxlen);
                // if you center arond and you find a palindrome of length len then starting point is (i-(len-1)/2)
                start = i -(len-1)/2;
                end = i +(len/2);
            }
        }
        return s.substr(start,maxlen);
    }
};