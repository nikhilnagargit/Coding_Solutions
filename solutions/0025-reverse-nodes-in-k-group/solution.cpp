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
// reverse function which will return the head of reversed linked list
    ListNode* reverse(ListNode* root){
        if(!root or root->next==nullptr){
            return root;
        }
        ListNode* first = root;
        ListNode* second = root->next;
        ListNode* third = root->next->next;
        first->next = nullptr;
        while(third!=nullptr){
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        return second;
    }
// find end function, it will return null if end is lesser than k otherwise it will return kth node
    ListNode* findnextKth(ListNode* root,int k){
        if(root==nullptr)return root;
        ListNode* first = root;
        int counter = 0;
        while(counter<k-1 and first->next!=nullptr){
            first = first->next;
            counter++;
        }
        if(counter!=k-1)
        return nullptr;
        return first;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = findnextKth(start,k);
        head = end;
        ListNode* end_backup = nullptr;
        while(end!=nullptr){ 
            ListNode* nextStart = end->next;
            end->next = nullptr;
            end = start;
            start = reverse(start);
            if(end_backup!=nullptr){
            end_backup->next = start;
            }
            end_backup = end;
            start = nextStart;
            end = findnextKth(start,k);
            }
        if(end_backup!=nullptr)   
        end_backup->next = start;
        return head;
        }
};
