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
    ListNode* reverseLL(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;

        head->next = nullptr;
        while(nxt){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr){
            int i=0;
            ListNode* end = curr;
            while(end and i<k-1){
                end = end->next;
                i++;
            }
            if(end){
            ListNode* temp = end->next;
            end->next = nullptr;
            ListNode* r = reverseLL(curr);
            prev->next =r;
            curr->next =temp;
            prev = curr;
            curr = temp;
            }
            else{
                curr = nullptr;
            }
        }
        return dummy->next;
    }
};
