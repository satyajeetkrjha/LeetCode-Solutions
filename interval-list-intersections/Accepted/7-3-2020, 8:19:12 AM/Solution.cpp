// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector <int> temp(2);
        vector <vector <int> > res;
        int Aptr =0;
        int Bptr =0;
        int sizeA= A.size();
        int sizeB= B.size();
        while(Aptr <sizeA && Bptr < sizeB){
            if(A[Aptr][0]<=B[Bptr][1] && A[Aptr][1]>=B[Bptr][0]){
                temp[0]=(max(A[Aptr][0],B[Bptr][0]));
                temp[1]=(min(A[Aptr][1],B[Bptr][1]));
                res.push_back(temp);              
            }
            if(A[Aptr][1]<=B[Bptr][1])
                Aptr++;
            else
              Bptr++;
            
        }
       return res;
    }
};