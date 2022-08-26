// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector <int> res;
        // map of sum of indices and the vector which contains all the elements with that sum
        map <int ,vector <int> > m; 
        int r = mat.size() ;
        if(r  == 0 )
            return res ;
        
        int c = mat[0].size();
        
        for(int i =0 ;i<r;i++){
            for(int j =0;j<c;j++){
                int sum = i +j ;
                m[sum].push_back(mat[i][j]);
            }
        }
        
        /*
        so our map has
        0  1
        1  2 4
        2  3 5 7 
        .......
        ......
        */
        int index =0 ;
        for(auto element :m){
            int sum = element.first ;
            vector <int> values= element.second ;
            if(index % 2 ==0){
                reverse(values.begin(),values.end());
                for(int i =0 ;i<values.size();i++){
                    res.push_back(values[i]);
                }
            }
            else{
                for(int i =0 ;i<values.size();i++){
                    res.push_back(values[i]);
                }
            }
            index++;
        }
        
        return res ;
        
        
        
        
        
    }
};