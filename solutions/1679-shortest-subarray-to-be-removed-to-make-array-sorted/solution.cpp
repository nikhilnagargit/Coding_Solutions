
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Find the longest non-decreasing prefix
        while (left + 1 < n && arr[left] <= arr[left + 1]) ++left;

        // If the entire array is sorted
        if (left == n - 1) return 0;

        // Find the longest non-decreasing suffix
        while (right > 0 && arr[right - 1] <= arr[right]) --right;

        // Initial assumption: remove everything between the prefix and suffix
        int minLength = min(n - left - 1, right);

        // Try merging prefix and suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                minLength = min(minLength, j - i - 1);
                ++i;
            } else {
                ++j;
            }
        }

        return minLength;
    }
};
