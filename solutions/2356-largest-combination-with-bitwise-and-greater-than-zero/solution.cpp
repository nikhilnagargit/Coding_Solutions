class Solution {
public:

    int largestCombination(vector<int>& candidates) {
        unordered_map<int,vector<int>> m;

        for(int i=0;i<candidates.size();i++){
            int n = candidates[i];
            int count = 0;
            while(n){
                if(n&1){
                    m[count].push_back(candidates[i]);
                }
                count++;
                n = n>>1;
            }
        }

        int max_length = 0;
        
        for(auto item:m){
            int s = item.second.size();
            max_length = max(max_length, s);
        }
        return max_length;
    }
};
