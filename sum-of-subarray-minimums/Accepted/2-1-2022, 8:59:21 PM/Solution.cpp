// https://leetcode.com/problems/sum-of-subarray-minimums

typedef long long ll;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector <int> left(n);
        vector<int> right(n);
        stack <pair<int ,int> > previous ,next ;
        
        for(int i =0 ;i<n ;i++){
            left[i] = i+1;
            right[i] = n-i;
        }
        
        for(int i =0 ;i< n;i++){
            
            
            while(!previous.empty() && previous.top().first > arr[i]){
                previous .pop();
            }
            
            left[i] = previous.empty() ? i+1  : i-previous.top().second;
            
            previous.push({arr[i],i});
            
            
            while(!next.empty() && next.top().first > arr[i]){
                auto x = next.top();
                next.pop();
                right[x.second] = i - x.second;
            }
            next.push({arr[i],i});
        }
        
        
        const int MOD = 1e9+7;
        int res = 0;
       
        for(int i =0 ;i<n ;i++){
           long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        return res ;
        
        
        
        
        
        
        
        
        
        
    }
};