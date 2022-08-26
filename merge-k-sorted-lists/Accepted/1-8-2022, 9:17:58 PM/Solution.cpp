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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n  = lists.size();
        if( n== 0){
            return NULL;
        }
        while(lists.size() >1){
            ListNode* a = lists[0];
            ListNode* b = lists[1];
            ListNode* merged = mergeList(a,b);
            lists.push_back(merged);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
        
    }
    
    ListNode* mergeList (ListNode* a,ListNode* b){
        if(a == NULL){
            return b ;
        }
        if(b == NULL){
            return a ;
        }
        if(a->val <= b->val){
            a->next = mergeList(a->next ,b);
            return a;
        }
        else{
            b->next = mergeList(a,b->next);
            return b;
        }
        
    }
    
};