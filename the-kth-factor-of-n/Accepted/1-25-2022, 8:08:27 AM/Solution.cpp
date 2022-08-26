// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int size ;
    
    void conditionalpush(priority_queue<int>&pq,int key){
        pq.push(key);
        if(pq.size() >size){
            pq.pop();
        }
    }
    int kthFactor(int n, int k) {
        size = k;
        priority_queue <int> pq ;
        
        
        
        for(int i =1 ;i*i<=n;i++){
            if(n%i==0){
                int first = i;
                int second = n/i;
                conditionalpush(pq,first);
                if(second!=first){
                    conditionalpush(pq,second);
                }
            }
        }
        return pq.size() == size ? pq.top():-1;
    }
};