// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        
        // sort the intervals first according to their start time
        sort(intervals.begin(),intervals.end()) ;
        
        /*
        for(auto &it: intervals){
            cout << it[0]<< " "<< it[1]<< endl;
        }
        */
        
        vector <vector <int> > res ;
        res.push_back(intervals[0]);
    
        
        for(int i =1 ;i<intervals.size();i++){
            // get the last element from the res vector 
            int sz = res.size() ;
           // cout <<"sz is "<< sz<< endl;
            // end time of first should be greater than the start time
            if(intervals[sz-1][1] >= intervals[i][0]){
              cout <<intervals[sz-1][1]<< " "<< intervals[i][1]<<endl;
              res[sz-1][1] = max(intervals[sz-1][1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        
        return res ;
    
        
    }
};