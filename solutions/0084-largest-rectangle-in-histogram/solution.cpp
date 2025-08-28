
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<int> st;                 // stores indices with increasing heights
        long long best = 0;

        for (int i = 0; i <= n; ++i) { // sentinel 0 at the end to flush the stack
            int cur = (i == n ? 0 : heights[i]);
            while (!st.empty() && cur < heights[st.top()]) {
                int h = heights[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();   // index of previous smaller element
                int width = i - left - 1;                // span where 'h' is the minimum
                best = max(best, 1LL * h * width);
            }
            st.push(i);
        }
        return (int)best;
    }
};

