// https://leetcode.com/problems/cutting-ribbons

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        
        int ans ;
        int low =1;
        int high = INT_MIN;
        for(int i =0 ;i<ribbons.size();i++){
            high = max(high ,ribbons[i]);
        }
        
        while(low <= high){
            int mid =(low+high)/2;
            
            int count =0 ;
            for(int i =0 ;i<ribbons.size();i++){
                count += ribbons[i]/mid;
            }
            if(count>=k){
                ans = mid ;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans ;
        
    }
};