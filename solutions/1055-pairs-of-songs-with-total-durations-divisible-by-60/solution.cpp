class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
int k=60;
    vector<int> freq(k, 0);
    int count = 0;

    for (int x : arr) {
        int r = x % k;
        int need = (k - r) % k;

        count += freq[need];
        freq[r]++;
    }
    return count;
}

    
};
