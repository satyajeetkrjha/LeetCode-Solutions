// https://leetcode.com/problems/sort-array-by-increasing-frequency


class Solution {
public:
Solution()
    {
  
        // Modify the class variable
        vector <int> freq(201,0);
    }
   
    bool compare(int a,int b){
        if(freq[a+100]== freq[b+100]){
            if(a>b){
                return true;
            }
            return false;
        }
        else {
            if(freq[a]>freq[b]){
                return true;
            }
            return false;
        }
    }
    vector<int> frequencySort(vector<int>& nums) {
       
        for(int i=0;i<nums.size();i++){
             freq[nums[i]+100]++;
        }
        sort(nums.begin(),nums.end(),compare)
    }
};