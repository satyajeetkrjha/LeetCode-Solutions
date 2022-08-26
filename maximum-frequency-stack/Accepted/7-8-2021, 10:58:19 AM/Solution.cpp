// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:
    int maximum_frequency;
    map <int,int > freq;
    map <int ,stack<int> > m;
    FreqStack() {
          maximum_frequency =0;
        
    }
    
    void push(int val) {
        ++freq[val] ; // increase the freuency of this new number
        maximum_frequency = max(maximum_frequency ,freq[val]) ;// update the maximum frquency
        m[freq[val]].push(val); // push the frequency and the corresponding number with it 
    }
    
    int pop() {
        // pop the element with the maximum frequency from stack
        int num = m[maximum_frequency].top(); 
        m[maximum_frequency].pop();
        // reduce the frequency of the popped number in the freq map
        --freq[num];
        
        // note that you decrease the maximum frequency whe stack with that maximum frequency is over and empty now
        if(m[maximum_frequency].size() ==0){
            m.erase(maximum_frequency);
            maximum_frequency --;
        }
        return num ;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */