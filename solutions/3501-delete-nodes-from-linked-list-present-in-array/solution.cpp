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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> nums_set(nums.begin(),nums.end());

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            //if curr node need to be removed
            if(nums_set.count(curr->val)){
                curr = curr->next;
            }
            //if curr node to be kept
            else{
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = nullptr;
        return dummy->next;
    }
};
