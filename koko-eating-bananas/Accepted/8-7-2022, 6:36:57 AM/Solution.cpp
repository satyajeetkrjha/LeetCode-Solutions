// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    
    bool caneat(vector<int>&piles ,int val,int h){
        int t =0;
        for(int i =0 ;i<piles.size();i++){
            if(piles[i]% val ==0){
                t+= (piles[i]/val);
            }
            else{
                t+= (piles[i]/val)+1;
            }
            if(t >h)
                return false;
        }
        return true;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high ;
        for(auto &it: piles){
            high = max(high,it);
        }
        
        while(low <high){
            int mid = (low+high)/2;
            if(caneat(piles,mid,h)){
                high = mid;
            }
            else
                low = mid+1;
        }
        return high ;
        
    }
};