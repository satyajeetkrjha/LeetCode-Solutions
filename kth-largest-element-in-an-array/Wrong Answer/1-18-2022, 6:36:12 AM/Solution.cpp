// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    vector <int> vec;
    
    int partition(int left ,int right ,int pivot_index){
        int pivot = vec[pivot_index];
        swap(vec[pivot_index],vec[right]);
        int store_index = left ;
        for(int i = left ;i<= right ;i++){
            if(vec[i]< pivot){
                swap(store_index,i);
                store_index++;
            }
        }
        swap(store_index,right);
        return store_index;
        
    }
    
    int quickselect(int left ,int right ,int kthsmallest){
        if(left == right){
            return vec[left];
        }
        int randpivot=rand()%(right-left)+(left+1); // make the pivot random
        int pivot_index = partition(left ,right ,randpivot);
        if(kthsmallest == pivot_index){
            return vec[kthsmallest];
        }
        else if(kthsmallest < pivot_index){
            return quickselect(left ,pivot_index-1,kthsmallest);
        }
        return quickselect(pivot_index+1,right,kthsmallest);
       
        
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
       vec= nums ;
       int n = nums.size();
       return quickselect(0,n-1,n-k); 
        
    }
};