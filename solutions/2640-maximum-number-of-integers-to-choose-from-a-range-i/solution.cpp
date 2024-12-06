class Solution {
    // 1,2,3,4,5.  
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banned_set(banned.begin(),banned.end());
        int left = 1;
        int right = 1;
        int sum = 0;
        int ans = 0;
        int window_size = 0;
        while(right<=n and left<=n and right<=maxSum and left<=maxSum){
            while(right<=n and banned_set.count(right)){
                right++;
            }
            if(right>n or right>maxSum) break;
            // cout<<right<<endl;
            if(maxSum>=sum+right){
                sum = sum + right;
                window_size++;
                right++;
            }
            else{
                if(!banned_set.count(left)){
                    sum-=left;
                    window_size--;
                    left++;
                }
                else{
                    left++;
                }
            }
            // cout<<window_size<<endl;
            ans = max(ans,window_size);
        }
        return ans;
    }
};
