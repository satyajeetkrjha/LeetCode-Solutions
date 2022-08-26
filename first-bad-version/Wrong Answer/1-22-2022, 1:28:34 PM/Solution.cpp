// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while(high-low >1){
            int mid =low+(high-low)/2;
            if(isBadVersion(mid)){
                high = mid;
            }
            else{
                low =mid+1;
            }
        }
        return low;
    }
};