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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        vector<int>peakIndexes ;
        if(!head || !head->next || !head->next->next){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;
    int i = 1;
    while(nxt){
        if((prev->val < curr->val && nxt->val < curr->val) 
        || (prev->val > curr->val && nxt->val > curr->val)){
            peakIndexes.push_back(i);
        }
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
        i++;
    }



    int maxDis, minDis;
    minDis = INT_MAX;
    int len = peakIndexes.size();

    if(len<2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
    }

    maxDis = peakIndexes[len-1]-peakIndexes[0];
    for(int i=1;i<len;i++){
        minDis = min(minDis, peakIndexes[i]-peakIndexes[i-1]);
    }
    ans.push_back(minDis);
    ans.push_back(maxDis);
        return ans;
    }
};
