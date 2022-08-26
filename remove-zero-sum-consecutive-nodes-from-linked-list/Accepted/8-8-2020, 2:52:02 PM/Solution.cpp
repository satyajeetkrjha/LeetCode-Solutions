// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* dummy  = new ListNode(0);
        dummy-> next = head;
        ListNode* cur  = dummy ;
        int presum =0;
        map <int ,ListNode*> m;
        while(cur!=NULL){
            presum+=cur->val;
            if(m.find(presum)!=m.end()){
                cur = m[presum]->next;
                int p = presum+cur->val;
                while(p!=presum){
                    m.erase(p);
                    cur = cur->next;
                    p+=cur->val;
                }
                m[presum]->next =cur->next;
                
            }
            else{
                m[presum] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};