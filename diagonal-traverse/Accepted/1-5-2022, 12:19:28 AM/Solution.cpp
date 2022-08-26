// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
         map <int ,vector <int> > m;
        int n = mat.size();
        int c = mat[0].size();
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<c;j++){
                m[i+j].push_back(mat[i][j]);
            }
        }
        vector <int> res ;
        for(auto it :m){
            int indexsum = it.first;
            vector <int> v  = it.second ;
            if(indexsum %2 ==0){
                reverse(v.begin(),v.end());
                for(int i =0 ;i<v.size();i++){
                    res.push_back(v[i]);
                }
            }else{
                for(int i =0 ;i<v.size();i++){
                    res.push_back(v[i]);
                }
            }
                
        }
        return res ;
        
        
        
        
    }
};