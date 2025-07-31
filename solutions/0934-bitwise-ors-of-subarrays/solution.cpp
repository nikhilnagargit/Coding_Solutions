class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> temp ;
        unordered_set<int> ans;
        for(int i=0;i<arr.size();i++){
            unordered_set<int> next;
            int curr = arr[i];
            next.insert(curr);
            for(auto item:temp){
                next.insert(item|curr);
            }
            temp = next;
            ans.insert(temp.begin(),temp.end());
        }
        return ans.size();
    }

};
