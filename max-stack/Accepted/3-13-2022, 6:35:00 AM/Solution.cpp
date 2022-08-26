// https://leetcode.com/problems/max-stack

class MaxStack {
    private :
    stack <int> s1;
    stack <int> s2 ;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || s2.top()<= x){
            s2.push(x);
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        if(x == s2.top()){
            s2.pop();
        }
        return x ;
    }
    
    int top() {
       return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int x = s2.top();
        stack <int> temp ;
        while(top()!= x){
            temp.push(pop());
        }
        pop();
        
        while(!temp.empty()){
            push(temp.top());
            temp.pop();
        }
        return x ;
        
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */