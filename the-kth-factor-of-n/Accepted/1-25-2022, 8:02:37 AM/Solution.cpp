// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    void conditionalpush( priority_queue <int> &pq ,int key,int k){
        
        
       
        pq.push(key);
        if(pq.size() >k){
            pq.pop();
        }
        
        
    }
    
    int kthFactor(int n, int k) {
        int first,second;
        priority_queue <int> pq;
        for(int i =1 ;i*i<=n;i++){
            if(n%i ==0){
                first = i ;
                second = n/i;
                conditionalpush(pq,first,k);
                if(second!=first)
                conditionalpush(pq,second,k);
            }
        }
        

        return pq.size() == k ? pq.top():-1;
        
    }
};