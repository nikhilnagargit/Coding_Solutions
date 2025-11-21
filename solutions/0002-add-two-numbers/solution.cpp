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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        int carry = 0;
        while(l1 and l2){
            int value = l1->val + l2->val + carry;
            if(value>=10){
                  value = value-10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode* newnode = new ListNode(value);
            dummy->next = newnode;
            dummy = newnode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
             int value = l1->val + carry;
            if(value>=10){
                value = value-10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode* newnode = new ListNode(value);
            dummy->next = newnode;
            dummy = newnode;
            l1 = l1->next;
        }

        while(l2){
             int value = l2->val + carry;
            if(value>=10){
               value = value-10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode* newnode = new ListNode(value);
            dummy->next = newnode;
            dummy = newnode;
            l2 = l2->next;
        }

        if(carry!=0){
            dummy->next = new ListNode(carry);
        }
        return ans->next;
    }
};
