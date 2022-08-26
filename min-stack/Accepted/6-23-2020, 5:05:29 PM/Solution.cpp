// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> first;
    stack<int> minstack;
    MinStack() {
        
    }
    
    
    void push(int x) {
        first.push(x);
        if(minstack.empty()){
            //cout<<"element in minstack is"<<x<<endl;
            minstack.push(x);
        }
        else{
            int top = minstack.top();
            if(x<top){
               // cout<<"element in minstack x is"<<x<<endl;
                minstack.push(x);
            }
            else{
                 // cout<<"element in minstack top is"<<top<<endl;
                  minstack.push(top);
            }
                
        }
        
    }
    
    void pop() {
         first.pop();
         minstack.pop();
    }
    
    int top() {
        return first.top();
    }
    
    int getMin() {
        return minstack.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */