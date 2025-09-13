class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_set<int> s;
        double avg = 0;
        for(auto& n:nums){
            avg+= n;
            s.insert(n);
        }
        avg = avg/(float)(nums.size());

        for(int i=1;i<=101;i++){
            if(s.count(i)) continue;
            if(i>avg){
                return i;
            }
        }
        return 0;
    }
};
