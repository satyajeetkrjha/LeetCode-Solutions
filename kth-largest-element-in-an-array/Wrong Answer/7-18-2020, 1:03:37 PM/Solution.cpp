// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
   int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    void printvector(vector <int> &nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int low =0;
        int high = nums.size()-1;
        int ans ;
        int pivotindex;
        while(low <high){
            cout<<"low is"<<low<<endl;
            cout<<"high is "<<high<<endl;
            cout<<"pivot to be found is element "<<nums[high]<<endl;
             pivotindex =partition(nums,low,high);
            printvector(nums);
            cout<<"pivotindex is"<<pivotindex<<endl;
            
             
             if(pivotindex < k) {
                low = pivotindex + 1;
            } else if (pivotindex > k) {
                high = pivotindex - 1;
            } else {
                break;
            }
        }
        return nums[pivotindex];
        
    }
};