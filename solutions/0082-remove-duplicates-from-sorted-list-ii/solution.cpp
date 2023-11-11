class Solution {
  public: ListNode * deleteDuplicates(ListNode * head) {
    ListNode * dummy = new ListNode(0, head);
    ListNode * prev = dummy;

    while(head!=nullptr){

        if(head->next!=nullptr and head->next->val==head->val){
            while(head and head->next!=nullptr and head->next->val==head->val){
                head = head->next;
            }
            prev->next = head->next;
        }
        else{
            prev = prev->next;
        }
        head  = head->next;

    }


    return dummy -> next;
  }
};
