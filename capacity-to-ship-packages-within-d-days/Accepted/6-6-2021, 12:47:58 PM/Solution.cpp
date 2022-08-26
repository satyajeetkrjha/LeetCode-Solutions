// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       
        int low =0;
        int high = 0;
        for(int i=0;i<weights.size();i++){
            low =max(low,weights[i]);
            high+=weights[i];
        }
        int ans=0 ;
        
        // low is the least possible weight and high is the highest possible weight
        while(low <=high){
            int mid =(low+high)/2;
            int val =checkfun(weights,mid);
            cout<<"low is "<<low<<endl;
            cout<<"high is "<<high <<endl;
            cout<<"mid is "<<mid<<endl;
            
           if (val > days){
               low =mid+1;
            }
            else {
                ans = mid;
                high =mid -1;
            }
            
        }
        return ans ;
    }
    int checkfun(vector <int> &weights,int weight){
        int current =0;
        int days = 1;
        for(int i=0;i<weights.size();i++){
            current = current+weights[i];
            if(current > weight){
                days ++;
                current = weights[i];
            }
        }
        return days ;
    }
};