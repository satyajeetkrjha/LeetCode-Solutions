// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue <int> pq ;
        
        for(auto &it: stones){
            pq.push(it);
        }
        
       // cout  << "size is "<< pq.size() << endl;
        
        while(pq.size() >1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
          //  cout << x << "   " << y << endl;
            if(x>y){
                pq.push(x-y);
            }
            if(y> x){
                pq.push(y-x);
            }
        }
        
        if(pq.size() == 0){
            return 0;
        }
        return pq.top();
        
    }
};