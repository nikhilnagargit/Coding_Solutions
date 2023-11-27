class Solution {
public:
    vector<vector<int>> moves = {
    {4, 6},
    {8, 6},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
    };
    int mod = 1000000007;
    int cache[5001][10];
    int solve(int remaining, vector<int>& nextNumbers){
        if(remaining==1) return nextNumbers.size();
        int count=0;
        for(auto nextNumber: nextNumbers){
            int curr = cache[remaining][nextNumber];
            if(curr == 0){
                curr = solve(remaining-1,moves[nextNumber]);
                cache[remaining][nextNumber] = curr;
            }
            count+= curr;
            count = count%mod;
        }
        return count;
    }
    int knightDialer(int n) {
        vector<int> nextNumbers = {0,1,2,3,4,5,6,7,8,9};
        return solve(n,nextNumbers);
    }
};
