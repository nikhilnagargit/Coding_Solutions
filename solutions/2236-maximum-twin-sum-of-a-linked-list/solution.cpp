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
 ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }
    int pairSum(ListNode* head) {
        if(!head)return 0;
        int count = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            count++;
        }
        int num = count/2 - 1;
        temp = head;
        while(num--){
            temp = temp->next;
        }
        ListNode* secondhalf = temp->next;
        temp->next = nullptr;
        ListNode* reversedSecondHalf = reverseList(secondhalf);
        int maxsum = 0;
        num = count/2;
        while(num--){
            maxsum = max(head->val+reversedSecondHalf->val,maxsum);
            head = head->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }
        return maxsum;
    }
};
