// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    
    vector<int> productExceptSelf(vector<int>& nums) {
    
       int n = nums.size();
       int left[n];
       int right[n];
       left[0] = right[n-1] =1 ;
        vector <int> prod;
        prod.resize(n);
        for(int i = 1 ;i< n;i++){
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i = n-2;i>=0 ;i--){
            right[i] = right[i+1]*nums[i+1];
            
        }
        cout << endl;
        /*
        for(int i =0 ;i<n;i++){
            cout <<left[i]<< " ";
        }
        cout << endl;
        for(int i =0 ;i<n;i++){
            cout << right[i]<< " ";
        }
        cout << endl;
        */
        for(int i =0 ;i<n;i++){
            prod[i] = left[i]*right[i];
        }
        return prod ;
         
        
    }
};