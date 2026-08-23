#include <vector>

class Solution {
private:
    void findCombinations(int idx, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                // Since the same number can be chosen unlimited times, we pass 'i' again instead of 'i + 1'
                findCombinations(i, target - candidates[i], candidates, current, result);
                current.pop_back(); // Backtrack
            }
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};