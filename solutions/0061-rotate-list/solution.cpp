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
        if(!head or k==0){
            return head;
        }

        int size = 0;
        ListNode* h = head;
        while(h){
            h=h->next;
            size++;
        }
        int target = k%size;

        ListNode* a = head;
        ListNode* b = head;

        while(target--){
            b=b->next;
        }

        while(b->next){
            b=b->next;
            a=a->next;
        }

        if(a->next){
        ListNode* temp = a->next;
        a->next = nullptr;
        b->next = head;
        return temp;
        }
        return head;
    }
};
