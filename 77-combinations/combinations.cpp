#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: combination of size k is complete
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Pruning: We only iterate up to a point where there are still 
        // enough numbers left to fill the remaining slots of 'current'.
        // Remaining slots = k - current.size()
        // Max valid starting number = n - (remaining slots) + 1
        for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
            current.push_back(i);                // Choose
            backtrack(i + 1, n, k, current, result); // Explore
            current.pop_back();                  // Un-choose (backtrack)
        }
    }
};