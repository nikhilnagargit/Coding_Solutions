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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* h = head;
        while(h){
            size++;
            h = h->next;
        }

        int target = size-n;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* nxt = dummy->next->next;

        int i=0;

        while(i<target){
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }

        prev->next = nxt;

        return dummy->next;
    }
};
