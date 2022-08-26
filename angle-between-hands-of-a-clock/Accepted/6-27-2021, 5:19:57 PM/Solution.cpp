// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int oneminangle =6;
        int onehourangle = 30;
        
      double minuteangle = (minutes*oneminangle);
        double hourangle =(hour %12 +minutes/60.0)*onehourangle;
        double diff = abs(hourangle - minuteangle) ;
       return min(diff ,360-diff);
    }
};