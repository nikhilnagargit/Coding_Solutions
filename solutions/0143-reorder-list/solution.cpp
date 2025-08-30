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

    void reorderList(ListNode* head) {
        //find mid and break in two lists
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        } 
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        ListNode* l1 = head;

        //reverse l2
        ListNode* prev = nullptr;
        ListNode* curr = l2;
        while(curr and curr->next){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(curr)
        curr->next = prev;
        //curr is new head
        l2 = curr;

        //merge l1 and l2 one by one
        ListNode* newhead = new ListNode();
        ListNode* temp= newhead;
        while(l1 and l2){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        head = newhead->next;
    }
};
