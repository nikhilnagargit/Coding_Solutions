class Solution {
public:
    long long count;
    void merge(vector<int>& nums,int l1,int h1, int l2, int h2){
        //we know l1 -> h1 is sorted same for l2->h2
        int j = l2;
        int counter = 0;
        for(int i=l1;i<=h1;i++){
            while(j<=h2 and ((long long)nums[i] > 2LL * (long long)nums[j])){
                counter++;
                j++;
            }
            count += counter;
        }

        //perform merge
        vector<int> v1(nums.begin()+l1, nums.begin()+h1+1);
        vector<int> v2(nums.begin()+l2, nums.begin()+h2+1);
        int i1 = 0;
        int i2 = 0;
        int i=l1;
        while(i1<v1.size() and i2<v2.size()){
            if(v1[i1]<v2[i2]){
                nums[i] = v1[i1];
                i1++;
            }
            else{
                nums[i] = v2[i2];
                i2++;
            }
            i++;
        } 
        while(i1<v1.size()){
            nums[i] = v1[i1];
            i1++;
            i++;
        }
        while(i2<v2.size()){
            nums[i] = v2[i2];
            i2++;
            i++;
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low==high){
            return;
        }
        int mid = low + (high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,mid+1,high);
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        // for(auto n: nums){
        //     cout<<n<<",";
        // }
        return count;
    }
};
