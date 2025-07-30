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
        ListNode* l3 = new ListNode(0);
        ListNode* ans = l3;
        ListNode* prev = nullptr;
        int carry = 0;
        while(l1 or l2 or carry){
            int a = 0;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }
            int b = 0;
            if(l2) {
                b = l2->val;
                l2 = l2->next;
            }
            int c = a+b+carry;
            if(c>9){
                 carry=1;
                 c = c-10;
            }
            else{
                carry=0;
            }
            l3->val = c;
            l3->next = new ListNode(0);
            prev = l3;
            l3 = l3->next;
        }



        prev->next = nullptr;
        return ans;

    }
};
