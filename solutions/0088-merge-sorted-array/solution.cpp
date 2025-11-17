class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m+n-1;
        int end1 = m-1;
        int end2 = n-1;
        while(end2>=0 and end1>=0){
            if(nums1[end1]<=nums2[end2]){
                nums1[p]=nums2[end2];
                end2--;
            }
            else{
                nums1[p]=nums1[end1];
                end1--;
            }
            p--;
        }
        while(end2>=0){
            nums1[p]=nums2[end2];
            end2--;
            p--;
        }

    }
};
