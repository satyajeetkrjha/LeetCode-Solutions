// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    
    priority_queue <int> low ; // max heap for lower half 
    priority_queue < int ,vector <int> ,greater <int> >high ; // this is for upper half    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.size() == 0 || low.top() > num){
            low.push(num);
        }
        else{
            high.push(num);
        }
        
        if(low.size() > high.size()+1){
            high.push(low.top());
            low.pop();
        }
        else if(high.size() > low.size()+1){
            low.push(high.top());
            high.pop();
        }
    
    }
    
    double findMedian() {
         if (low.size() > high.size()){
             return low.top();
         }        
         else if(high.size()>low.size()){
             return high.top();
         }
         return (low.top()+high.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */