class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        int m = *max_element(v.begin(),v.end());
        int sum = 0;
        for(auto& i : v){
            if(i==m)
            sum+= i;
        }
        return sum;
    }
};
