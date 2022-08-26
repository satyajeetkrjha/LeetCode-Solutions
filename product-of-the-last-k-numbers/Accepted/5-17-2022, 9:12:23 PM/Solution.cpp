// https://leetcode.com/problems/product-of-the-last-k-numbers

class ProductOfNumbers {
public:
    vector <int> v ={1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num !=0){
            v.push_back(v.back()*num);
        }
        else{
         v = {1};   
        }
    }
    
    int getProduct(int k) {
        if( v.size()>k){
            return v.back() /(v[v.size()-k-1]);
         }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */