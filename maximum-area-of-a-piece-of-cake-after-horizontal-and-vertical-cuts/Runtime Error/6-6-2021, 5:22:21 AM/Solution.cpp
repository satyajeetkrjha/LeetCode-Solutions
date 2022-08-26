// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxHeight = max(horizontalCuts[0],h-horizontalCuts[n-1]);
        int maxWidth = max(verticalCuts[0],w-verticalCuts[m-1]);
        
        for(int i=1;i<n;i++){
            maxHeight = max(maxHeight,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<m;i++){
            maxWidth = max(maxWidth ,verticalCuts[i]-verticalCuts[i-1]);
        }
        long long int ans = (maxHeight*maxWidth)%1000000007;
        return ans ;
        
    }
};