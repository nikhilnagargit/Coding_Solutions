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

        int counta = 0;
        int countb = 0;

        while(a){
            a = a->next;
            counta++;
        }
        while(b){
            b = b->next;
            countb++;
        }
        a = headA;
        b = headB;
        if(counta>countb){
            int diff = counta-countb;
            while(diff--){
                a = a->next;
            }
        }
        else{
            int diff = countb-counta;
            while(diff--){
                b = b->next;
            }
        }
        while(a and b){
            if(a==b) return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};
