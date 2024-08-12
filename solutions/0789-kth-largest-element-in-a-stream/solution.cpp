class KthLargest {
public:
    int K ;
    vector<int> Nums;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(),nums.end(),std::greater<int>());
        this->K = k;
        this->Nums = nums;
    }
    
    int add(int val) {
        Nums.push_back(val);
        int idx = Nums.size()-2;
        while(idx>=0 and Nums[idx]<Nums[idx+1]){
            swap(Nums[idx],Nums[idx+1]);
            idx--;
        }
        return Nums[K-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 *
 **/
