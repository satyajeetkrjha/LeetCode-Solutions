// https://leetcode.com/problems/next-greater-node-in-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> vec ;
        ListNode* temp = head ;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        
        stack <int> st;
        vector <int> res(vec.size());
        int sz = vec.size();
        for(int i = sz-1; i>=0 ;i--){
            if(!st.empty()){
                while(!st.empty() && st.top() <= vec[i]){
                    st.pop();
                }
            }
            res[i] = st.empty() ? 0 : st.top();
            cout <<"stack size is "<< st.size()<< endl;
            st.push(vec[i]);
        }
        return res ;
    }
};