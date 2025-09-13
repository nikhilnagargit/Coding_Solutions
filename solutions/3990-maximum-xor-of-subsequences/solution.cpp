class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int basis[32] = {0};
        for (int x : nums) {
            int v = x;
            for (int b = 31; b >= 0; --b) {
                if (((unsigned)v >> b) & 1u) {
                    if (!basis[b]) { basis[b] = v; break; }
                    v ^= basis[b];
                }
            }
        }
        // Compute maximum XOR from the basis
        int best = 0;
        for (int b = 31; b >= 0; --b) {
            if ((best ^ basis[b]) > best) best ^= basis[b];
        }
        return best;
    }
};

