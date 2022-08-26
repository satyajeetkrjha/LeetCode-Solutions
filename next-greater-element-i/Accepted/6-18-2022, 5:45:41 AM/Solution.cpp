// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      
        map <int ,int> m;
        stack <int> st ;
        for(int i =0 ;i< nums2.size();i++){
            while(!st.empty() && nums2[i] > st.top()){
                m[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        while(!st.empty()){
            m[st.top()] =-1;
            st.pop();
        }
        
        vector <int> res ;
        for(int i =0 ;i<nums1.size();i++){
            res.push_back(m[nums1[i]]);
        }
        return res ;
        
        
        
    }
};