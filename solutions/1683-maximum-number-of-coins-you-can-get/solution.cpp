class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(),piles.end());
        int i = piles.size()-2;
        int count = 0;
        while(count<piles.size()/3){
            ans+= piles[i];
            i = i-2;
            count++;
        }
        return ans;
    }
};
