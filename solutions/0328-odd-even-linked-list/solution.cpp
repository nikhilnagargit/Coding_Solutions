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
        
        if(head==NULL or head->next==NULL or head->next->next==NULL){
            return head;
        }
        
          ListNode* head1 = head;
          ListNode* head2 = head->next ;
          ListNode* temp1 = head1;
          ListNode* temp2 = head2;
          head = head->next->next;
        
        int count=1;
        while(head!=NULL){
            if(count%2!=0){
                temp1->next = head;
                temp1= temp1->next;
            }
            else{
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head->next;
            count++;
        }
        
        temp1->next = head2;
        temp2->next = NULL;
        return head1;
        
    }
};
