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
    pair<ListNode* ,ListNode*> reverseList(ListNode* head){
        if(!head)return {nullptr,nullptr};
        if(!head->next) return {head,head};
        ListNode* last = head;
        ListNode* prev = nullptr;
        while(head and head->next){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head->next = prev;
        return {head,last};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int i=1;
        while(curr){
            if(i==k){
                ListNode* temp = curr->next;
                curr->next = nullptr;
                i=0;
                auto p = reverseList(prev->next);
                ListNode* first = p.first;
                ListNode* last = p.second;
                prev->next = first;
                prev = last;
                prev->next = temp;
                curr = temp;
            }
            else{
                curr = curr->next;
            }
            i++;
        }
        return dummy->next;
    }
};
