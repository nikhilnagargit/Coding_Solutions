class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> myset;
        vector<int> myvec;
        for(auto& i: nums){
            myset.insert(i);
        }
        for(int i=1;i<=nums.size();i++){
            if(myset.find(i)==myset.end()){
                myvec.push_back(i);
            }
        }
        return myvec;
    }
};
