// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n= nums.size();
      int count_zero=0;
        int count_one=0;
      int count_two =0;
        int count_three =0;
        for(int i=0;i<n;i++){
            if(nums[i] ==0)
                count_zero++;
            else if (nums[i]==1)
                count_one++;
            else if(nums[i]==2)
                count_two ++;
        }
        int index =0;
        while(count_zero>0){
         
            nums[index]=0;
            index++;
            count_zero--;
           
                
        }
        while(count_one >0){
             cout<<"index is "<<index<<endl;
            cout<<"count_one is "<<count_one<<endl;
            nums[index]=1;
            count_one --;
            index++;
        }
        while(count_two>0){
             
            nums[index]=2;
            count_two--;
            index++;
        }
        
        
    }
};