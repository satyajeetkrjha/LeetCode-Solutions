// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int window_size =0;
        for(int i =0;i<data.size();i++){
            if(data[i] ==1)
                window_size++; 
        }
        // note window size is the number if ones in the array 
        int left = 0 ;int right =0;
        int cnt_one =0 ;// count of one in current window 
        int max_one =0 ;// maximum one in current window
        
        while(right <data.size()){
             cnt_one+=data[right++];
            if(right - left >window_size){
                cnt_one-=data[left++];
            }
            max_one = max(max_one ,cnt_one);
        }
        return window_size -max_one ;
    }
};