// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    priority_queue <int> pq ;
    int lastStoneWeight(vector<int>& stones) {
        int sz = stones.size();
        for(int i =0 ;i<sz;i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>2){
            int y = pq.top();pq.pop();
            int x = pq.top();pq.pop();
            //cout <<"x and y are"<< x << " "<< y << endl;
            if(x != y)
                pq.push(y-x);
        }
        
        //cout <<"size is "<< pq.size()<< endl;
        if(pq.size() == 0)
            return 0;
        else 
            return pq.top();
        
    }
};