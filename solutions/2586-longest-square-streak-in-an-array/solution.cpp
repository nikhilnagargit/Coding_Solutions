class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> myset (nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        long long streak  = -1;
        long long largestnum = nums[nums.size()-1];
        for(long long num:nums){
            long long curr_streak = 1;
            long long square = num*num;
            while(myset.count(square) and square<=largestnum){
                curr_streak++;
                square = square*square;
            }
            streak = max(streak,curr_streak);
        }
        if(streak<=1){
            return -1;
        }
        return streak;
    }
};
