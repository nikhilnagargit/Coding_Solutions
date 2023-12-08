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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next)return head;
        ListNode* odd = head;
        ListNode* evenHead = odd->next;
        ListNode* even = evenHead;
        while(even->next!=nullptr and even->next->next!=nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        if(even->next==nullptr){
        }
        else{
            odd->next = odd->next->next;
            even->next = nullptr;
            odd = odd->next;
        }
        odd->next = evenHead;
        return head;
    }
};
