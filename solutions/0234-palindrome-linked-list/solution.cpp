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
    
 bool isPalindrome(ListNode* head) {
        ListNode* slow = head,*fast = head,*temp = head;
        // Moving slow pointer to middle of linked list
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        ListNode* prev = NULL,*curr = slow,*next;
        // Reversing the second half of the linked list
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Comparing prev which is currently the head of the reversed second half with temp which points to the head of the first half
        while(prev != NULL)
        {
            if(prev->val != temp->val)
                return false;
            prev = prev->next;
            temp = temp->next;
        }
        return true;
    }
};
