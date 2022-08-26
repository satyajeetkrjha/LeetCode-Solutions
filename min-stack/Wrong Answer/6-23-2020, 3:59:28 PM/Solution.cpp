// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    vector<int> v;
    int minElem;
    MinStack() {
        
    }
    
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            v.push_back(x);
            minElem =x;
        }
        else{
            if(x>=minElem){
                s.push(x);
                v.push_back(x);
            }
            else {
               
                s.push(2*x-minElem);
                 minElem =x;
                v.push_back(2*x-minElem);
            }
        }
        cout<<"min till now is "<<minElem<<endl;
        for(int i =0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        
    }
    
    void pop() {
        int t=s.top();
        s.pop();
        cout<<"t is"<<t<<endl;
        cout<<"minElem after pop is "<<minElem<<endl;
        
        if(t<minElem){
            minElem =2*minElem-t;
        } 
    }
    
    int top() {
        int t= s.top();
        s.pop();
        cout<<"minElem in top is "<<minElem<<endl;
        cout<<"t in top is  "<<t<<endl;
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