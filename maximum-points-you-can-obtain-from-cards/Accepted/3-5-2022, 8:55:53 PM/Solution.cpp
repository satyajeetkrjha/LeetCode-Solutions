// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     
        int frontscore = 0 ;
        int rearscore = 0 ;
        for(int i =0 ;i< k;i++){
            frontscore  += cardPoints[i];
        }
        int n = cardPoints.size();
        
        int ans = frontscore ;
        for(int i = k-1 ;i>=0 ;i--){
            frontscore  = frontscore - cardPoints[i];
            rearscore = rearscore + cardPoints[n-(k-i)];
            int runningsum = frontscore + rearscore;
            ans = max(ans,runningsum);
        }
        return ans ;
        
        
    }
};