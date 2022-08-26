// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      set <int> s;
      int n = nums.size();
        
      for(int i =0 ;i<n;i++){
          s.insert(nums[i]);
      }
        for ( auto num: s){
            cout<<"num is "<<num<<endl;
        }
        cout<<endl;
        
      // iterate through the set and pick a number 
        int longeststreak =0;
        
        for( auto elem :s){
            int currentstreak =1;
            
            // first check that a number just smaller than this does not exist in set
            // this will stop from tle 
            // imagine your set contains 1 2 3 4 100 200 so once we have calculated for 1,2,3,4 we should not calculate again for 2,3,4 and similarly we should not calculate for 3,4 because we already have a longer answer already found when we did  1 ,2 ,3,4 so checking this elem -1 makes sene and prevents tle
            if(s.find(elem-1) == s.end()){
                
                while(s.find(elem+1)!= s.end()){
                    elem ++;
                    currentstreak++;
                    
                }
                longeststreak = max(longeststreak ,currentstreak);
                
            }
        }
            return longeststreak ;
            
            
        
        
    }
};