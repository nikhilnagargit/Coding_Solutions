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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* prev  = head;
        ListNode* curr = head->next;
        ListNode* nex = head->next->next;
        head->next = nullptr;
        while(nex!=nullptr){
            curr->next = prev;
            prev = curr;
            curr = nex;
            nex = nex->next;
        }
        curr->next = prev;
        return curr;
    }
};
