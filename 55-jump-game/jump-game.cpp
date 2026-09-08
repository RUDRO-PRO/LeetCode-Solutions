#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the furthest reachable point, return false
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest reachable index
            maxReach = std::max(maxReach, i + nums[i]);
            
            // Optimization: if we can already reach the last index, return true
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};