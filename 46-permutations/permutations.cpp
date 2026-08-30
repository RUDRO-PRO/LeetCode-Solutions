#include <vector>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }

private:
    void backtrack(int start, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base case: if start index reaches the end, a full permutation is formed
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // Place nums[i] at the current 'start' position
            std::swap(nums[start], nums[i]);

            // Recurse for the next index
            backtrack(start + 1, nums, result);

            // Backtrack: restore original array state for subsequent iterations
            std::swap(nums[start], nums[i]);
        }
    }
};