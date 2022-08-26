// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack <int> st ;
        vector <int> res ;
        map <int ,int> m;
        for(int i =0 ;i<nums.size()-1;i++){
         //   cout <<"nums i "<< i << "    "<< nums[i]<< endl;
            while(!st.empty() && st.top()< nums[i]){
               // cout <<"st.top is "<< st.top() << " ->"<< nums[i]<< endl;
                m[st.top()] = nums[i];
                st.pop();
            }
            st.push(nums[i]);
        }
        while(!st.empty()){
            m[st.top()] =-1;
            st.pop();
        }
        
        
        int x = nums[nums.size()-1];
        int val = -1;
        for(int i =0 ;i<nums.size();i++){
            if(nums[i] >x){
                val = nums[i];
                break;
            }
        }
        m[x] = val ;
        
        for(int i =0 ;i<nums.size();i++){
            res.push_back(m[nums[i]]);
        }
        
        return res ;
        
    }
};