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
    bool operator()(ListNode* a, ListNode* b) const {
        // return true if a should come after b, i.e. a.val > b.val
        if(a and b)
        return a->val > b->val;
        return true;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* temp = new ListNode();
        ListNode* dummy = temp;
        while(l1 and l2){
            if(l1->val<l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }
            else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy=dummy->next;
        }
        if(l1){
            dummy->next = l1;
        }
        if(l2){
            dummy->next = l2;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        priority_queue<ListNode*,vector<ListNode*>,Solution> heap;
        for(int i=0;i<lists.size();i++){
            heap.push(lists[i]);
        }
        while(heap.size()>1){
            ListNode* a = heap.top();heap.pop();
            ListNode* b = heap.top();heap.pop();
            heap.push(merge(a,b));
        }
        return heap.top();
    }
};
