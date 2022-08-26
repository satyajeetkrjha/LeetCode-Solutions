// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
     
        stack <pair <int ,int> > previous ,next ;
        int n = arr.size();
        vector <int> left(n);
        vector<int> right(n);
        
        for(int i =0 ;i<n ;i++){
            left[i] = i+1;
            right[i] = n-i;
        }
        
        
        for(int i =0 ;i<n;i++){
            
            while(!previous.empty() && previous.top().first >arr[i]){
                previous.pop();
            }
            left[i] = previous.empty() ? i+1:i- previous.top().second;
            previous.push({arr[i],i});
            
            
            while(!next.empty() && next.top().first > arr[i]){
                auto x = next.top();
                next.pop();
                right[x.second] = i - x.second ;
            }
            
            next.push({arr[i],i});
            
        }
        
        int ans = 0 ;
        const int mod = 1e9+7;
        for(int i =0 ;i<n ;i++){
           ans = (ans + arr[i]*left[i]*right[i])%mod; 
        }
        return ans ;
    }
};