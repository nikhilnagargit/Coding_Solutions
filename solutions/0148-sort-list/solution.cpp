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

// find mid 
    ListNode* findMid(ListNode* head){
        if(!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* temp1,ListNode* temp2){
        if(!temp1) return temp2;
        if(!temp2) return temp1;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(temp1 and temp2){
            if(temp1->val>temp2->val){
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
            else{
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
        }
        if(!temp1){
            temp->next = temp2;
        }
        if(!temp2){
            temp->next = temp1;
        }
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* mid = findMid(head);
        ListNode* left_start_node = head;
        ListNode* right_start_node = mid->next;
        mid->next = nullptr;
        ListNode* left = sortList(left_start_node);
        ListNode* right = sortList(right_start_node);
        return merge(left,right);
    }
};
