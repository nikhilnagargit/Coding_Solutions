class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m+n,0);

        int i=0;
        int j=0;
        int k=0;

        while(i<m and j<n){
            if(nums1[i]<=nums2[j]){
                v[k]=nums1[i];
                k++;
                i++;
            }
            else{
                v[k]=nums2[j];
                k++;
                j++;
            }
        }

        while(i<m){
            v[k] = nums1[i];
            k++;
            i++;
        }

        while(j<n){
            v[k] = nums2[j];
            k++;
            j++;
        }

        nums1 = v;

    }
};
