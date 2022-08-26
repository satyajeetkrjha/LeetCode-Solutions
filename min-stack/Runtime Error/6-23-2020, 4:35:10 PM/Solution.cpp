// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long int> s;
    int minElem;
    MinStack() {
        
    }
    
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            
            minElem =x;
        }
        else{
            if(x>=minElem){
                s.push(x);
                
            }
            else {
               
                 s.push(2*x-minElem);
                 minElem =x;
                
            }
        }
        
        
        
    }
    
    void pop() {
        int t=s.top();
        s.pop();
    
        
        if(t<minElem){
            minElem =2*minElem-t;
        } 
    }
    
    int top() {
        int t= s.top();
       
        if(t<minElem){
            return minElem;
        }
        else
            return t;
        
    }
    
    int getMin() {
            return minElem;
        
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