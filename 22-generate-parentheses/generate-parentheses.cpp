#include <vector>
#include <string>

class Solution {
private:
    void backtrack(std::vector<string>& result, std::string current, int open, int close, int n) {
        // If the current string has reached the maximum length of 2 * n, add it to results
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // We can add an opening parenthesis if we haven't used all 'n' opening parentheses
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // We can add a closing parenthesis if the number of closing parentheses is less than the opening ones
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};