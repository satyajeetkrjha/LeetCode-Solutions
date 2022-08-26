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
        group[m[val]].push(val);
    }
    
    int pop() {
        int top = group[maxfreq].top();
        group[maxfreq].pop();
        m[top]--;
        if(group[maxfreq].size() == 0){
            //group.erase(maxfreq);
            maxfreq--;
            
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */