class Solution {
public:
bool divideArray(vector<int>& nums) {
    bitset<501> bs;
    for(const int n:nums) bs.flip(n);
    return bs.none();
}
};
