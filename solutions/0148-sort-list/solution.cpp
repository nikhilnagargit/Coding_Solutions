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
    ListNode* mergeList(ListNode* head1,ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        head1 = sortList(head1);
        head2 = sortList(head2);
        ListNode* head;
        if(head1->val<head2->val){head = head1; head1 = head1->next;}
        else {head = head2; head2 = head2->next;}

        ListNode* prev = head;
        while(head1!=nullptr and head2!=nullptr){
            if(head1->val<head2->val){
                prev->next = head1;
                prev = head1;
                head1 = head1->next;
            }
            else{
                prev->next = head2;
                prev = head2;
                head2 = head2->next;
            }
        }
        if(!head1){
            prev->next = head2;
        }
        else{
            prev->next = head1;
        }
        return head;
    }

    ListNode* partition(ListNode* head){
        if(!head or !head->next)return head;
    
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        return mergeList(head,head2);
    }

    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)return head;
        return partition(head);
        
    }
};
