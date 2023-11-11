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
        ListNode* list1dummy = new ListNode(0);
        ListNode* l1 = list1dummy;
        ListNode* list2dummy = new ListNode(0);
        ListNode* l2 = list2dummy;
        while(head){
            if(head->val<x){
                l1->next = head;
                head = head->next;
                l1 = l1->next;
            }
            else{
                l2->next = head;
                head = head->next;
                l2 = l2->next;
            }

        }
            l2->next = nullptr;
            l1->next = list2dummy->next;
            return list1dummy->next;
    }
};
