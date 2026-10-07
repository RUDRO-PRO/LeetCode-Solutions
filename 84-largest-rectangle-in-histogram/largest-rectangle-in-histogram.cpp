#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Use height 0 at the virtual index n to flush the stack
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // If stack is empty, width extends from 0 to i - 1 (width = i)
                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = std::max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};