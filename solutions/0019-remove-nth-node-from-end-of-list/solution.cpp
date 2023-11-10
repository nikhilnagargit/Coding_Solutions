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
        ListNode* a = head;
        ListNode* b = head;
        
        int count = n;
        while(count--){
            b = b->next;
        }
        ListNode* prev = nullptr;
        while(b){
            b = b->next;
            prev = a;
            a = a->next;
        }
        if(prev){
        prev->next = a->next;
        return head;
        }
        return head->next;
    }
};
