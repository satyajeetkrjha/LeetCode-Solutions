// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:
    map <int ,int > m ;
    map <int ,stack<int>>group ;
    int maxfreq =0;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxfreq = max(maxfreq,++m[val]);
        int freqval = m[val];
        group[freqval].push(val);
    }
    
    int pop() {
        int top = group[maxfreq].top();
        group[maxfreq].pop();
        if(group[maxfreq].size() == 0){
            maxfreq--;
        }
        return top ;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */