class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // make hash map
        unordered_map<int,vector<int>>m;
        for(auto item:adjacentPairs){
            m[item[0]].push_back(item[1]);
            m[item[1]].push_back(item[0]);
        }

        // find the beginning point in hash map
        int start_value;
        for(auto item:m){
            if(item.second.size()==1){
                start_value = item.first;
                break;
            }
        }
        // begin from start_value and values that does not exist in ans set, should be inserted in set, and treated as new start value
        int prev=INT_MAX;
        vector<int>ans;
        ans.push_back(start_value);

        while(ans.size()<m.size()){
            for(auto item:m[start_value]){
                if(item!=prev){
                    ans.push_back(item);
                    prev = start_value;
                    start_value = item;
                    break;
                }
            }
        }
        return ans;
    }
};
