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
    vector<Interval> employeeFreeTime(vector<vector<Interval>> s) {
    
        typedef pair<int, int> id_pos;
  auto cmp = [&](const id_pos& i1, const id_pos& i2) {
    return s[i1.first][i1.second].start > s[i2.first][i2.second].start;
  };

  std::priority_queue<id_pos, std::vector<id_pos>, decltype(cmp)> pq(cmp);

  // Start by pushing the first interval for every employee
  for (int i = 0; i < s.size(); ++i) pq.push({i, 0});

  // Variable to store all free intervals
  vector<Interval> ret;
  
  // End of last interval
  int end{s[pq.top().first][pq.top().second].start};
  while (!pq.empty()) {
    auto [id, pos] = pq.top();
    pq.pop();

    auto& cur_interval = s[id][pos];
    if (cur_interval.start > end)
      ret.push_back(Interval{end, cur_interval.start});

    end = max(end, cur_interval.end);
    if(++pos < s[id].size()) pq.push({id, pos});

  }
  return ret;
        
        
    }
};