class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans = 0 ;
        for(auto item:m){
            int count = item.second;
            if(count==1){
                return -1;
            }
            else if(count%3==0){
                ans+= count/3;
            }
            else if(count%3 ==1){
                ans += (count-4)/3 + 2;
            }
            else if(count%3 == 2){
                ans += (count-2)/3 + 1;
            }
        }
    return ans;
    }
};
