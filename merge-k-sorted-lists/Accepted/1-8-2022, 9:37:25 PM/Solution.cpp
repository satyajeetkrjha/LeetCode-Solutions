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
        if(lists.size() == 0 ){
            return NULL;
        }
        
        while(lists.size()>1){
            lists.push_back(mergeList(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
        
    }
    
    ListNode* mergeList(ListNode* l1 ,ListNode* l2){
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val <= l2->val){
            l1->next = mergeList(l1->next ,l2);
            return l1;
        }
        else{
            l2->next = mergeList(l1,l2->next);
            return l2 ;
        }
    }
};