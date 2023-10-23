/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* findNode(Node* head,int index){
        while(index--){
            head = head->next;
        }
        return head;
    }

    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return nullptr;
        }
        Node* head_bkp = head;

        Node* head2 = new Node(head->val);
        Node* head2_bkp = head2;

        // make a copy
        Node* a = head;
        int index = 0;
        while(a->next!=NULL){
            a->val = index++;
            a = a->next;
            head2->next = new Node(a->val);
            head2 = head2->next;
        }
        a->val = index;
        head2->next = nullptr;

        head2 = head2_bkp;
        int random_index;
        // for every random index, find node and assign
        while(head!=nullptr){
            if(head->random==nullptr){
                head->random = nullptr;
     
            }
            else{

            head2->random = findNode(head2_bkp,head->random->val);
            }
            head = head->next;
            head2 = head2->next;
        }
        return head2_bkp;
    }
};
