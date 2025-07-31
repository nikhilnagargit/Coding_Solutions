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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy = new ListNode(-10000);
        dummy->next = head;
        ListNode* ans = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(nxt){
            if(curr->val==nxt->val){
                // start looping and find end
                ListNode* end = nxt;
                while(end!=nullptr and curr->val==end->val){
                    end = end->next;
                }
                prev->next = end;
                curr = end;
                if(end!=nullptr)
                nxt = end->next;
                else
                nxt = nullptr;
            }
            else{
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
        }
        return dummy->next;
    }
};
