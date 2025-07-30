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
    Node* copyRandomList(Node* head) {
        Node* head2_parent = new Node(0);
        Node* h2 = head2_parent;
        Node* h1 = head;
        // map address to idx and store
        unordered_map<Node*,int> old_add_idx;
        int i=1;
        while(h1){
            old_add_idx[h1] = i;
            h1 = h1->next;
            i++;
        }
        //reset h1
        h1 = head;


        //create new ll and map index of random also
        unordered_map<int,int> mp_idx_idx;
        unordered_map<int,Node*> new_idx_add;
        i=1;
        while(h1){
            h2->next = new Node(h1->val);
            new_idx_add[i] = h2->next;
            mp_idx_idx[i] = old_add_idx[h1->random];
            h1 = h1->next;
            h2 = h2->next;
            i++;
        }
        
        //reset h1 and h2
        h2 = head2_parent;
        h1 = head;



        // map address to idx for new ll
        h2= h2->next;
        i=1;
        while(h2){
            h2->random = new_idx_add[mp_idx_idx[i]];
            i++;
            h2 = h2->next;
        }


        return head2_parent->next;
    }
};
