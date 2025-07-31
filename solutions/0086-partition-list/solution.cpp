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
    ListNode* partition(ListNode* head, int x) {
        ListNode* s = new ListNode();
        ListNode* s_copy = s;
        ListNode* l = new ListNode();
        ListNode* l_copy = l;

        while(head){
            if((head->val)<x){
                s->next = new ListNode(head->val);
                s = s->next;
            }
            else{
                l->next = new ListNode(head->val);
                l = l->next;
            }
            head = head->next;
        }
        s->next = l_copy->next;

        return s_copy->next;
    }
};
