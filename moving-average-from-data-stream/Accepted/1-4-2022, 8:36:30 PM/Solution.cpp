// https://leetcode.com/problems/moving-average-from-data-stream

class MovingAverage {
    int windowsize ;
    int index ;
    int total ;
    deque <int> values ;
public:
    MovingAverage(int size) {
        windowsize = size;
        index =0 ;
        total =0;
        
    }
    
    double next(int val) {
        index++;
        if(index <= windowsize){
            total += val ;
            values.push_back(val);
            return (double) total/index ;
        }
        else{
            int sub = values[0];
            values.pop_front();
            values.push_back(val);
            total = total - sub + val;
            return (double) total/ windowsize ;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */