// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int sz =s.size();
        if(sz*k == 0){
            return 0;
        }
        map <char ,int> rightmostposition;
        int left =0 ;
        int right =0 ;
        int maxlen  = 1;
        
        while(right <sz){
            rightmostposition[s[right]] = right;
            right++;
            
            if(rightmostposition.size() == k+1){
                int lowestIndex = INT_MAX;
                for(auto[element,index]:rightmostposition){
                  //  cout <<"element ...  "<< element<< " index "<< index << endl; 
                    lowestIndex = min(lowestIndex,index);
                }
                rightmostposition.erase(s[lowestIndex]);
                left = lowestIndex+1;
            }
            maxlen = max(maxlen ,right-left);        
        }
    
        return maxlen ;
    }
};