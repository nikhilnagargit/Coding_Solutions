class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        vector<int>ans;
        int gayab ;
        int duplicate;
        for(int i=1;i<=nums.size();i++){
            if(m.find(i)==m.end()){
                gayab = i;
            }
            else if(m[i]==2){
                duplicate = i;
            }
        }
        ans.push_back(duplicate);
        ans.push_back(gayab);
        return ans;
    }
};
