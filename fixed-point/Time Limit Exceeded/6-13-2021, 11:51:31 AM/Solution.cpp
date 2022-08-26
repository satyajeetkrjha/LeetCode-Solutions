// https://leetcode.com/problems/fixed-point

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
       int ans =-1;
        int low =0;
        int high = arr.size()-1;
        cout<<"low is "<<low <<endl;
        cout<<"high is "<<high <<endl;
        while(low <high){
            int mid =(low+high)/2;
            cout<<"Inside low and high are "<<low <<" "<<high <<endl;
            cout<<"mid is "<<mid <<endl;
            if (arr[mid]> mid){
                high =mid;
            }
            
            else if (arr[mid]<mid){
                low =mid;
            }
            
            else if(arr[mid] == mid){
                ans =mid;
                high =mid;        
                    
            }
           
        }
    return ans ;
    }
};