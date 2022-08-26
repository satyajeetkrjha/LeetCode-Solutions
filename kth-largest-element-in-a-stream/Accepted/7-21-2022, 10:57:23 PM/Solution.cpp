// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    int heapsize;
    priority_queue <int ,vector<int> ,greater <int> > pq ;
    KthLargest(int k, vector<int>& nums) {
        heapsize = k;
        for(auto &it:nums){
            pq.push(it);
            if(pq.size() >k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > heapsize){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */