// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    
    bool caneat(vector<int>&piles ,int val,int h){
        int t =0;
        /*
        
        Imagine that your speed is 4 and there are 9 banana in piles 
        then we can't eat it two mins and will instead need 3 mins to eat all 9 .
        So logic is check 9%4 and that's not 0 so just add+1 in integer division 
        else take the integer division .
        For logic of this problem ,read the editorial .
        
        */
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