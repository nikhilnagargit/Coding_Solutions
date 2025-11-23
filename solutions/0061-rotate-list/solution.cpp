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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0) return head;
        ListNode* counter = head;
        int count = 0;
        while(counter){
            counter = counter->next;
            count++;
        }
        if(k>=count){
            k = k%count;
        }
        if(k==0) return head;
        ListNode* curr = head;
        while(k-- and curr){
            curr = curr->next;
        }

        ListNode* prev = head;
        while(curr and curr->next){
            curr = curr->next;
            prev = prev->next;
        }
        ListNode* temp = prev->next;
        prev->next = nullptr;
        curr->next = head;
        return temp;
    }
};
