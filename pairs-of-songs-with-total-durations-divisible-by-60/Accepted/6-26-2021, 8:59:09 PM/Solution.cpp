// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
      int remainders [60];
        for(int i =0;i<60;i++){
            remainders[i] =0;
        }
        int ans =0;
        for(int i =0;i<time.size();i++){
            if(time[i]%60 ==0){
                cout<<"zeroth remainder for i= "<<i<< " is "<<remainders[0]<<endl;
                ans+= remainders[0];
                cout<<"ans is "<<ans<<endl;
            }
            else{
                ans +=remainders[60 - time[i]%60];
            }
            remainders[time[i]%60]++;
        }
        // cout<<"remainders[0] at last is "<<remainders[0]<<endl;
        // cout<<remainders[20]<<endl;
        // cout<<remainders[40]<<endl;
       
        return ans;
    }
};