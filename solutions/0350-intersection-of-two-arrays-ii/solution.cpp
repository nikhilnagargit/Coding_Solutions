class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        vector<int>ans;
        for(int& num:nums1){
            map1[num]++;
        }
        for(int& num:nums2){
            if(map1.find(num)!=map1.end() and map1[num]>0){
                ans.push_back(num);
                map1[num]--;
            }
        }
        return ans;
    }
};
