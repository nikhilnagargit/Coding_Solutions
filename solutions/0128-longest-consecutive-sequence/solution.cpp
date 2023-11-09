class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> s;
        for(auto i:nums)
         s.insert(i);
int len=1;
        int longest = 1;
int prev = *s.begin();
s.erase(prev);
        while(!s.empty()){
            int curr = *s.begin();
            if(prev==curr-1){
                len++;
                if(len>longest){
                    longest = len;
                }
            }
            else{
                len=1;
            }
            prev = curr;
            s.erase(curr);
        }
        return longest;
    }
};
