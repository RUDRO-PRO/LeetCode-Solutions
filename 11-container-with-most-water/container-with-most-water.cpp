class Solution {
public:
    int maxArea(vector<int>& height) {
        // Optimize I/O operations for LeetCode's execution environment
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Find the bottleneck height for the current container
            int current_height = min(height[left], height[right]);
            
            // Calculate and update the max area
            int current_area = current_height * (right - left);
            if (current_area > max_area) {
                max_area = current_area;
            }
            
            // Micro-optimization: Fast-forward past any lines that are shorter 
            // than or equal to our current height bottleneck. 
            // They mathematically cannot produce a larger area.
            while (left < right && height[left] <= current_height) {
                left++;
            }
            while (left < right && height[right] <= current_height) {
                right--;
            }
        }
        
        return max_area;
    }
};