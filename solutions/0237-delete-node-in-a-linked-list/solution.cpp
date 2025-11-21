/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // you can move all the next values to prev node. and delete the last node
        //or we can 
        if(node->next){
            node->val = node->next->val;
            node->next = node->next->next;
        }

    }
};
