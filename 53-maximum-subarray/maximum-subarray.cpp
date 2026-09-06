#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            // Decide to extend the previous subarray or start a new one
            current_sum = std::max(nums[i], current_sum + nums[i]);
            // Track the overall maximum
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum;
    }
};