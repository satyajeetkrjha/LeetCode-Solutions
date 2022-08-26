// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

typedef long long int ll ;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        ll maxHeight = max(horizontalCuts[0],h-horizontalCuts[n-1]);
        ll maxWidth = max(verticalCuts[0],w-verticalCuts[m-1]);
        
        for(int i=1;i<n;i++){
            if(maxHeight <horizontalCuts[i]-horizontalCuts[i-1]){
                maxHeight =horizontalCuts[i]-horizontalCuts[i-1];
            }
        }
        for(int i=1;i<m;i++){
            if(verticalCuts[i]-verticalCuts[i-1] >maxWidth){
                maxWidth =verticalCuts[i]-verticalCuts[i-1];
            }
           
        }
        long long int ans = (maxHeight*maxWidth)%1000000007;
        return ans ;
        
    }
};