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
    ListNode* reverseLL(ListNode* h){
        if(!h or !h->next)return h;
        ListNode* prev = nullptr;
        ListNode* curr = h;
        ListNode* nxt = h->next;
        while(nxt){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        return curr;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next and fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* newh = slow->next;
        slow->next = nullptr;
        ListNode* start = reverseLL(newh);
        ListNode* start2 = head;
        while(start and start2){
            if(start->val != start2->val) return false;
            start = start->next;
            start2 = start2->next;
        }
        return true;
    }
};
