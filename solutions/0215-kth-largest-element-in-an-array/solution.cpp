class Solution {
public:
    void heapify(vector<int>& nums, int root, int last_index){
        int left = 2*root+1;
        int right = 2*root+2;
        if(left>last_index){
            return;
        }
        int largest;
        if(left<=last_index and nums[left]<nums[root]){
            largest = root;
        }
        else{
            largest = left;
        }
        if(right<=last_index and nums[right]>nums[largest]){
            largest = right;
        }
        // swap largest with root
        if(largest!=root){
        swap(nums[largest],nums[root]);

        // repeat for the subtree which was swapped
        heapify(nums,largest,last_index);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // convert array in heap;
        for(int i=nums.size()/2;i>=0;i--){
            heapify(nums,i,nums.size()-1);
        }

        for(auto i:nums){
            cout<<i<<",";
        }

        // now pop k values from heap;
        int ans;
        for(int i=0;i<k;i++){
            ans = nums[0];
            nums[0] = nums[nums.size()-1-i];
            heapify(nums,0,nums.size()-1-i);
        }

        return ans;
    }
};
