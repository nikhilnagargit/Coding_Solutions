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
   ListNode* reverseLL(ListNode* head){
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        return first;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *leftNode,*rightNode,*firstNode,*lastNode = nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        int i=1;
        while(curr){
            if(i==left){
                leftNode = prev;
                firstNode = curr;
            }
            if(i==right){
                rightNode = curr->next;
                lastNode = curr;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }

        lastNode->next = nullptr;
        leftNode->next = nullptr;
        ListNode* newHead = reverseLL(firstNode);


        leftNode->next = lastNode;
        if(firstNode)
        firstNode->next= rightNode;

        return dummy->next;
    }
};
