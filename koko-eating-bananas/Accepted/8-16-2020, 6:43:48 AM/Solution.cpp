// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low =1;
        int high =INT_MIN ;
        for(int i=0;i<piles.size();i++){
            high = max(piles[i],high);
        }
        // high can be the maximum speed of eating bananas 
        //  low <=eating speeed <= high this is what eating speed can be
        int speed ;
        while(low <=high){
            int mid = (low+high)/2;
            int timeTaken = timetoeat(mid,piles);
            if(timeTaken ==H){
                // ith this speed of mid all bananas can be finished so we got answer
             return mid;
            }
            else if (timeTaken >H){ // we need bigger numbers in denomintor 
                low = mid+1;
            }
            else {
                high = mid -1;
            }
        }
        return low;
        
    }
    int timetoeat(int speed , vector <int> piles){
        int time =0;
        for(int i =0;i<piles.size();i++){
            time +=ceil(piles[i]/(double)speed);
        }
        return time ;
    }
};