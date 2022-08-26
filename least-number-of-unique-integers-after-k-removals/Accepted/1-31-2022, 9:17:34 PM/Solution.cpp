// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map <int ,int > m ;
        for(auto& it :arr){
            m[it]++;
        }
       
        priority_queue <int ,vector<int> ,greater<int> > pq ;
        
        for(auto& it:m){
            pq.push(it.second);
        }
        
        /*
        cout <<"Priority queue elements"<< endl;
        for(auto& it :m){
            cout << it.second <<" "<< endl;
        }
        
       cout <<"pq.size() is "<< pq.size()<< endl;
        
        */
        while(k> 0){
            k = k- pq.top();
            if(k>=0){
                pq.pop();
            }
        }
        
        return pq.size();
        
        
        
    }
};