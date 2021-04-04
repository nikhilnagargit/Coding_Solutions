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
        
        if(head->next==NULL){
            head = NULL;
            return head;
        }
        
        
        ListNode* a = head;
        ListNode* b = head;
        ListNode* prev = head;
        
        n = n-1;
        while(n--){
            b = b->next;
        }
        
        while(b->next!=NULL){
            prev = a;
            a = a->next;
            b = b->next;
        }
        
        
        if(a==head){
            head = head->next;
            return head;
        }
        
        
        prev->next = a->next;
        
        
        
        
        return head;
        
        
    }
};
