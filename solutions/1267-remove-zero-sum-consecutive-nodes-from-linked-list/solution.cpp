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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> m;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while(temp){
            sum+= temp->val;
            // cout<<sum<<endl;
            if(m.find(sum)==m.end()){
                m[sum] = temp;
                temp = temp->next;
                continue;
            }
            // remove intermediate nodes from m[sum] node
            ListNode* tempNode = m[sum];
            ListNode* t = tempNode->next;
            tempNode->next = temp->next;
            // delete entries from map
            int tempsum = sum;
            while(t!=temp and t!=NULL){
                tempsum += t->val;
                m.erase(tempsum);
                // cout<<tempsum<<" ",
                t = t->next;
            }
        
            temp = temp->next;
        }
        return dummy->next;
    }
};
