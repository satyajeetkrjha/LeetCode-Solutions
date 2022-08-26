// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    
    // Just maintain a min heap of size k all the time .When you do this ,the element at the
    // top in a min heap is the smallest amomg all k that we have in heap so our kth largest is nothing but the top of min heap 
    
    
    int sizeofheap ;
    priority_queue <int ,vector <int> ,greater <int> > pq;
    KthLargest(int k, vector<int>& nums) {
        sizeofheap = k;
       for(int i =0 ;i<nums.size();i++){
           pq.push(nums[i]);
           if(pq.size() >k){
               pq.pop();
           }
       }    
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sizeofheap){
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