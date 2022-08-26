// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        int i =0 ;int j =0 ;
        vector <vector <int> > res;
        vector <int> temp(2);
        while(i <n && j <m){
            int l = max(firstList[i][0],secondList[j][0]);
            int r = min(firstList[i][1],secondList[j][1]);
            if( l <=r){
                temp[0]= l;
                temp[1]=r;
                res.push_back(temp);
            }
            if(firstList[i][1]<secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res ;
    }
};