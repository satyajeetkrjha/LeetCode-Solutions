// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        vector <int> res ;
        res.resize(10005,-1);
        stack <int> st ;
        for(int i = n-1;i>=0;i--){
            while(!st.empty()  &&  nums2[i] > st.top()){
                st.pop();
            }
            res[nums2[i]] = st.empty()  ? -1 : st.top();
            st.push(nums2[i]);
        }
        
        vector <int> ans ;
        for(int i =0 ;i< nums1.size();i++){
            ans.push_back(res[nums1[i]]);
        }
        return ans ;
        
        
        
        
        
    }
};