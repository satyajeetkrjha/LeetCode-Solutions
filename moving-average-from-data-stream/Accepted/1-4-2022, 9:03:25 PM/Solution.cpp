// https://leetcode.com/problems/moving-average-from-data-stream

class MovingAverage {
    int windowsize ;
    int index ;
    int total ;
    deque <int> q;
public:
    MovingAverage(int size) {
        windowsize = size ;
        index =0;
        total =0;
    }
    
    double next(int val) {
        index ++;
        if(index <=windowsize){
            total += val;
            q.push_back(val);
            return (double) total /index;
        }
        else{
            int sub = q[0];
            q.pop_front();
            q.push_back(val);
            total = total - sub + val;
            return (double) total/windowsize;
            
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */