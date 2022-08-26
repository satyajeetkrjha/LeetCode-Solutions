// https://leetcode.com/problems/number-of-boomerangs

typedef long long int ll;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int n = points.size();
        
        int res =0;
        
        for(int i =0 ;i< n;i++){
            map <ll ,ll> m;
            for(int j =0 ;j< n;j++){
                ll dx = points[j][0] - points[i][0];
                ll dy = points[j][1] - points[i][1];
                ll val = dx*dx + dy*dy ;
                m[val]++;
            }
            for(auto el:m){
                if(el.second > 1){
                    res += el.second *(el.second-1);
                }
            }   
        }
        
        return res ;
        
        
    }
};