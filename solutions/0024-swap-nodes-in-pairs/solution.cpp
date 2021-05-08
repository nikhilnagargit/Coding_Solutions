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
    
    
    ListNode* swap_list(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* temp = head->next->next;
        swap(head->val,head->next->val);
        head->next->next = swap_list(temp);
        return head;
    }
    
    ListNode* swapPairs(ListNode* head) {
         return swap_list(head);
    }
};
