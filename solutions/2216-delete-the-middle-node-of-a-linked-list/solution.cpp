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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or !head->next) return nullptr;
        ListNode* beforeslow = new ListNode();
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            fast = fast->next->next;
            beforeslow = slow;
            slow = slow->next;
        }
        if(fast->next==nullptr){

        }
        else{
            beforeslow = slow;
            slow = slow->next;
        }
        beforeslow->next = beforeslow->next->next;
        return head;
    }
};
