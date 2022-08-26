// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    
    bool caneat(int speed,int time ,vector <int> &piles){
        int t =0;
        for(auto &it:piles){
            if(it %speed == 0){
                t+= it/speed;
            }
            else
                t+= (it/speed)+1;
        }
        if(t>time)
            return false;
        return true ;
    }
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 ;
        int high =0;
        for(int i =0 ;i<piles.size();i++){
            high = max(high,piles[i]);
        }
        cout <<"high is "<< high << endl;
        while(low <high){
            int mid= (low+high)/2 ;
            if(caneat(mid,h,piles)){
                high =mid;
            }
            else
                low =mid+1;
        }
        return high ;
        
    }
};