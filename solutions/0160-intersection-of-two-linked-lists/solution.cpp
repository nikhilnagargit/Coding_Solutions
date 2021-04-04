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
        ListNode* a = headA;
        ListNode* b = headB;
        
        if(headA==NULL or headB==NULL)
            return NULL;
        
        int counta=1;
        int countb=1;
        
        while(a->next!=NULL){
          a = a->next;
            counta++;
        }
        while(b->next!=NULL){
          b = b->next;
            countb++;
        }
        
        if(a!=b)
            return NULL;
        
        a = headB;
        b = headA;
        
        if(counta>countb){
            int diff= counta-countb;
            while(diff-->0 ){
                b = b->next;
            }
        }
        else if(countb>counta){
            int diff = countb-counta;
            while(diff-->0 ){
                a = a->next;
            }
        }       
        
        while(a!=b){
            a = a->next;
            b = b->next;
        }
        
        return a;

    }
};
