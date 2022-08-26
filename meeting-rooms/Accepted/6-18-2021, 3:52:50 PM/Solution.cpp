// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        if(intervals.empty() ||  intervals.size() == 1  ){
            return true ;
        }
        // sort the meeting on basis of start time
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<=intervals.size()-2;i++){
            vector <int> x = intervals[i]; // first meeting
            vector <int> y = intervals[i+1]; // second meetigng
            cout<<"x is "<<x[0]<< " "<<x[1]<<endl;
            cout<<"y is "<<y[0]<<" "<<y[1]<<endl;
            if( x[1] > y[0]){
                return false;
            }
            
        }
        return true;
        
        
    }
};