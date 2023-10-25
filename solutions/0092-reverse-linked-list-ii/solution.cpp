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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }


public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr or head->next ==nullptr or left==right){
          return head;
        }
        ListNode* first_part;
        if(left==1){
          first_part = nullptr;
        }else{
          int i=2;
          first_part = head;
          while(i<left){
            first_part=first_part->next;
            i++;
          }
        }
        int j=1;
        ListNode* last_part;
        last_part = head;
        while(j<right){
          last_part=last_part->next;
          j++;
        }

        if(last_part->next==nullptr){
          last_part = nullptr;
        }
        else{
          ListNode* tm = last_part;
          last_part = last_part->next;
          tm->next = nullptr;
        }


        if(last_part!=nullptr and first_part!=nullptr){
        // reverse middle lsit
         ListNode* tem = first_part->next;
          ListNode* start  = reverse(tem);
        // attach in between
          first_part->next =start;
          tem->next = last_part;
          return head;
        }
        else if(first_part!=nullptr){
        // reverse middle lsit
          ListNode* start  = reverse(first_part->next);
        // attach in between
          first_part->next =start;
          return head;
        }
        else if(last_part!=nullptr){
          ListNode* t = head;
          head = reverse(head);
          t->next = last_part;
          return head;
        }
        else{
          return reverse(head);
        }

return head;

    }
};
