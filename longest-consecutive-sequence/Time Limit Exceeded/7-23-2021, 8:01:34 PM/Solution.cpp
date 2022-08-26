// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      set <int> s;
      int n = nums.size();
        
      for(int i =0 ;i<n;i++){
          s.insert(nums[i]);
      }
        
      // iterate through the set and pick a number 
        int longeststreak =0;
        
        for( auto elem :s){
            int currentstreak =1;
            
            // first check that a number just smaller than this does not exist in set
            
                
                while(s.find(elem+1)!= s.end()){
                    elem ++;
                    currentstreak++;
                    
                }
                longeststreak = max(longeststreak ,currentstreak);
                
            }
        
            return longeststreak ;
            
            
        
        
    }
};