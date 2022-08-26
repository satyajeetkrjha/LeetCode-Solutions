// https://leetcode.com/problems/employee-free-time

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        typedef pair <int,int> id_pos;
        auto comp = [&](const id_pos& i1 ,const id_pos &i2){
            return schedule[i1.first][i1.second].start > schedule[i2.first][i2.second].start ;
        };
        priority_queue< id_pos ,vector <id_pos>,decltype(comp)> pq(comp) ;
        int sz = schedule.size();
        for(int i =0 ;i< sz;i++){
            pq.push({i,0});
        }
        vector<Interval> res;
  
        int end{schedule[pq.top().first][pq.top().second].start};
        while(!pq.empty()){
            auto [id,pos] = pq.top();
            pq.pop();
            
            auto &cur_interval = schedule[id][pos];
            if(cur_interval.start > end){
                res.push_back({end,cur_interval.start});
            }
            end = max(cur_interval.end,end);
            if(++pos < schedule[id].size()){
                pq.push({id,pos});
            }
        }
        
        return res ;
    }
};