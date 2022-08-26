// https://leetcode.com/problems/maximum-number-of-points-with-cost

typedef long long ll ;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        ll n = points.size(); // n rows
        ll m = points[0].size(); // m columns
        
        vector <ll> pre(m);
        
        for(int i =0 ;i<m;i++){
            pre[i] = points[0][i];
        }
        
        for(int i =0 ;i< n-1;i++){
            vector <ll> cur(m,0);
            vector <ll> left(m,0);
            vector<ll> right(m,0);
            left[0] = pre[0];
            right[m-1] = pre[m-1];
            for(int j =1 ;j< m;j++){
                left[j] = max(left[j-1]-1,pre[j]);
            }
            for(int j = m-2;j>=0 ;j--){
                right[j] = max(right[j+1]-1,pre[j]);
            }
            
            for(int j =0 ;j< m;j++){
                cur[j] = max(left[j],right[j])+ points[i+1][j];
            }
            pre = cur;    
            
        }
        ll ans = 0;
        for (int i = 0; i < m; ++i)
            ans = max(ans, pre[i]);
        return ans;
        
        
        
        
        
        
        
        
        
    }
};