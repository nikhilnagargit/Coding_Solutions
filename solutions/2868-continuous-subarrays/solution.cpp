class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> m;
        long long total = 0;
        int left = 0;
        int right = 0;

        while(right<nums.size()){
            m[nums[right]]++;
            right++;
            while(((prev(m.end())->first)-(m.begin()->first))>2){
                m[nums[left]]--;
                if(m[nums[left]]==0){
                    m.erase(nums[left]);
                }
                left++;
            }
            total += right-left;
            // right++;
        }
        // total+= right-left;

        return total;
    }
};
