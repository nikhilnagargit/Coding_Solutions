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
        unordered_map<Node*,Node*> oldNewMap;
        Node* newhead = new Node(0);
        Node* currnew = newhead;
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            currnew->next = temp;
            currnew = temp;
            oldNewMap[curr] = temp;
            curr = curr->next;
        }
        newhead =newhead->next;
        currnew = newhead;
        Node* currold = head;
        while(currnew){
            currnew->random = oldNewMap[currold->random];
            currnew = currnew->next;
            currold = currold->next;
        }
        return newhead;
    }
};
