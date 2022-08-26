// https://leetcode.com/problems/rle-iterator

class RLEIterator {
    
vector <int> vec;   
int index ;    
    
public:
    
    RLEIterator(vector<int>& encoding) {
        vec = encoding ;
        index  =0 ;
    }
    
    int next(int n) {
        
        int sz = vec.size();
        while(index < sz){
            if(vec[index] <n){
                n = n -vec[index]; 
                index = index +2 ;
            }
            else {
                vec[index] -= n ;
                return vec[index+1];
            }
        }
        return -1;
        
    
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */