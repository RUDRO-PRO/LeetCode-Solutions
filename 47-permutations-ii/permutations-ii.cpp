#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);
        
        // 1. Sort to bring duplicates adjacent to each other
        std::sort(nums.begin(), nums.end());
        
        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, 
                   std::vector<bool>& used, 
                   std::vector<int>& current, 
                   std::vector<std::vector<int>>& result) {
        // Base case: formed a full permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current branch
            if (used[i]) continue;

            // Duplicate pruning:
            // If the current element equals the previous element and the previous element 
            // was not used in this branch, it means we are trying to start/continue a branch 
            // with a duplicate value that has already been explored at this position.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used, current, result);

            // Backtrack (Un-choose)
            current.pop_back();
            used[i] = false;
        }
    }
};