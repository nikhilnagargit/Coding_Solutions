class Solution {
public:

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

    bool canSortArray(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp;
        int prevSetBits = countSetBits(nums[0]);
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int currSetBits = countSetBits(nums[i]);
            if(prevSetBits==currSetBits){
                temp.push_back(nums[i]);
            }
            else{
                v.push_back(temp);
                temp.clear();
                temp.push_back(nums[i]);
                prevSetBits = currSetBits;
            }
        }
        if(temp.size()>0){
            v.push_back(temp);
        }

        vector<pair<int,int>> hlv;
        for(int i=0;i<v.size();i++){
            int highest = v[i][0];
            int lowest = v[i][0];
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]<lowest){
                    lowest = v[i][j];
                }
                if(v[i][j]>highest){
                    highest = v[i][j];
                }
            }
            hlv.push_back({highest,lowest});
        }

        for(int i=1;i<hlv.size();i++){
            if(hlv[i-1].first > hlv[i].second){
                return false;
            }
        }
        return true;

    }
};
