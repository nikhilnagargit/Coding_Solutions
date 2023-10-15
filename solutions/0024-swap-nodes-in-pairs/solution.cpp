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
    ListNode* swapPairs(ListNode* head) {

        if(head==nullptr or head->next==nullptr){
            return head;
        }
        ListNode* ans_head = head->next;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* curr = nullptr;

        ListNode* temp = second->next;
        second->next = first;
        first->next = temp;
        curr = first;
        while(curr!=nullptr and curr->next!=nullptr and curr->next->next!=nullptr){
     
            first = curr->next;
            second =curr->next->next;
            temp = second->next;
            second->next = first;
            first->next = temp;
            curr->next = second;
            // alot new curr
            curr =first;
        }

        return ans_head;


    }
};
