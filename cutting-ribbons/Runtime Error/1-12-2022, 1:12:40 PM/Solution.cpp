// https://leetcode.com/problems/cutting-ribbons

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        
        int low = 0 ;
        int high = 0;
        
        for(int i = 0 ;i<ribbons.size();i++){
            high+= ribbons[i];
        }
        high=high+1;
        while(high-low >1){
            int mid =(low+high)/2;
             int count =0 ;
            for(int i =0 ;i<ribbons.size();i++){
                count += ribbons[i]/mid;
            }
            if(count>=k){
                low = mid;
            }
            else{
              high =mid;
            }
        }
        return low ;
    }
};