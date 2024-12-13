
class Solution {


public:
    long long findScore(vector<int>& nums) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > heap; 
        unordered_set<int> marked_indexes;
        for(int i=0;i<nums.size();i++){
            pair<int,int> p ;
            p.first = nums[i];
            p.second = i;
            heap.push(p);
        }
        long long total = 0;
        while(!heap.empty()){
            auto p = heap.top();heap.pop();
            if(marked_indexes.count(p.second)) continue;
            total += p.first;
            marked_indexes.insert(p.second+1);
            marked_indexes.insert(p.second-1);
        }
        return total;
    }
};
