// https://leetcode.com/problems/cutting-ribbons

/*
low = some value that's guaranteed to work
high = some value that's guaranteed to not work
While high-low>1 (
mid=(high+low)/2
If mid works low = mid
else high = mid
)
Take any binary search problem and think invariant
General rule is, you are getting to find the boundary b where some f(x) is true only when x<=b
Just set some x'<=b to be low, some x'>b to be high and update low=mid if f(mid) is true
Haven't seen a single binary search problem where this won't work
*/


class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        
        int low = 0 ;
        int high = INT_MIN;
        
        for(int i = 0 ;i<ribbons.size();i++){
            high = max(high,ribbons[i]);
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