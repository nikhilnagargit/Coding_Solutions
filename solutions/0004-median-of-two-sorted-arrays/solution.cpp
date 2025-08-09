class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = total / 2;

        int left = 0;
        int right = m;

        while (left <= right) {
            int midA = left + (right - left) / 2;
            int midB = half - midA;

            int leftA = (midA > 0) ? nums1[midA - 1] : INT_MIN;
            int rightA = (midA < m) ? nums1[midA] : INT_MAX;

            int leftB = (midB > 0) ? nums2[midB - 1] : INT_MIN;
            int rightB = (midB < n) ? nums2[midB] : INT_MAX;

            if (leftA <= rightB && leftB <= rightA) {
                if (total % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }
                return min(rightA, rightB);
            } else if (leftA > rightB) {
                right = midA - 1;
            } else {
                left = midA + 1;
            }
        }

        // Should never reach here if inputs are valid
        return 0.0;
    }
};

