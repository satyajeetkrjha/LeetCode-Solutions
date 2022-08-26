// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena=0;int lenb=0;
        
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        
        while(tempa!=NULL){
            lena++;
            tempa= tempa->next;
        }
        while(tempb!=NULL){
            lenb++;
            tempb=tempb->next;
            
        }
        cout<<"l1 and l2 are"<<lena<<" "<<lenb<<endl;
        int diff =0;
        
        if(lena >lenb){
            diff =lena-lenb;
            tempa=headA;
            tempb=headB;
        }
        else{
            diff =lenb-lena;
            tempa=headB;
            tempb=headA;
        }
        cout<<"diff is "<<diff<<endl;
        
        while(diff>0){
            tempa = tempa->next;
            diff --;
        }
        cout<<"tempa->val is "<<tempa->val<<endl;
        while(tempa !=tempb){
            tempa = tempa->next;
            // cout<<"tempa->val is "<<tempa->val<<endl;
            // cout<<"tempb->val is "<<tempb->val<<endl;
            tempb= tempb->next;
        }
        return tempa;
        
        
       
    }
};