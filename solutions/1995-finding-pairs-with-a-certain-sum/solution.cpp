class FindSumPairs {
public:
    vector<int> v2;
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->v2 = nums2;
        for(auto& i:nums1){
            this->m1[i]++;
        }
        for(auto& i:nums2){
            this->m2[i]++;
        }
    }
    
    void add(int index, int val) {
        int i = this->v2[index];
        this->m2[i]--;
        this->v2[index]+= val;
        this->m2[i+val]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(auto& item:this->m1){
            if(this->m2.find(tot-item.first)!=m2.end()){
                c+= item.second * m2[tot-item.first] ; 
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
