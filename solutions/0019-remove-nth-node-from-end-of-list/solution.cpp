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
        ListNode* dummy=  new ListNode();
        dummy->next = head;
        ListNode* A = dummy;
        ListNode* B = dummy;
        while(n--){
            B = B->next;
        }
        while(B->next){
            B = B->next;
            A = A->next;
        }
        A->next = A->next->next;
        return dummy->next;
    }
};
