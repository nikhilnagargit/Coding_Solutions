class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> m;
        while(n){
            int rem = n%10;
            n= n/10;
            m[rem]++;
        }
        int ans = -1;
        int minfreq = INT_MAX;
        for(auto& item:m){
            if(item.second < minfreq){
                minfreq = item.second;
                ans = item.first;
            }
            else if(item.second==minfreq){
                ans = min(item.first,ans);
            }
        }
        return ans;
    }
};
