// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map <int ,int > m ;
        for(auto it:arr){
            m[it]++;
        }
        priority_queue <int > pq ;
        for(auto [key,value]:m){
            pq.push(value);
        }
        
        int counter = 0 ;
        int sz = arr.size();
        while(!pq.empty()){
            int element = pq.top();
            pq.pop();
            sz = sz -element ;
            counter ++;
            if(sz <= (arr.size()/2)){
                return counter ;
            }
        }
        return counter ;
        
    }
};