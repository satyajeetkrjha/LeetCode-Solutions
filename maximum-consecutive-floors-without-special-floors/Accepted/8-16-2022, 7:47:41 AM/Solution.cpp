// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        int n = special.size();
        sort(special.begin(),special.end());
        int maxval = INT_MIN;
        for(int i =0  ;i<n-1;i++){
           // cout <<"val is "<< special[i+1]-special[i]-1<<endl;
            maxval = max(maxval ,max(special[i+1]-special[i]-1,0));
           // cout <<"maxval inside "<<maxval << endl;
        }
       // cout <<"max2 is "<<top-special[n-1] << endl;
      //  cout <<"max1 is "<<special[0]-bottom<<endl;
        int maxval1 = special[0]-bottom;
        int maxval2 = top-special[n-1];
        maxval = max(maxval,max(maxval1,maxval2));
        return maxval;
        
        
    }
};