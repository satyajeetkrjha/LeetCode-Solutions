// https://leetcode.com/problems/merge-k-sorted-lists

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
    
    typedef pair<int, ListNode*> PII;
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
        priority_queue<PII, vector<PII>, greater<PII> > pq;
        
        int sz  = lists.size();
        if(sz == 0)
            return NULL ;
        
        for(int i =0 ;i<sz;i++){
            auto *cur = lists[i];
            if(cur!=NULL){
                cout << cur->val << endl;
                pq.push({cur->val,cur});
            }            
        }
        // what if all lists were null 
        if(pq.size() == 0) 
            return NULL ;
        
     
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy ;
        
        while(pq.size() >0){
           auto[val,temp] = pq.top();
           pq.pop();
           if(temp->next!=NULL){
               pq.push({temp->next->val,temp->next});
           }
          cur->next = temp;
            cur = cur->next;
            
            
        }
        cur->next = NULL;
        
        return dummy->next ;
        
    }
};