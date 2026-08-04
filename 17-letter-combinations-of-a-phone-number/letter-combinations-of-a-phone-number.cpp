#include <vector>
#include <string>

class Solution {
private:
    const std::vector<std::string> phoneMap = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination is of the same length as digits
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        std::string letters = phoneMap[digits[index] - '0'];

        // Iterate through all possible letters for this digit
        for (char letter : letters) {
            current.push_back(letter);           // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back();                  // Un-choose (Backtrack)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }
        
        // Reserve memory to avoid dynamic reallocation overhead
        int maxCombinations = 1;
        for (char d : digits) {
            maxCombinations *= (d == '7' || d == '9') ? 4 : 3;
        }
        result.reserve(maxCombinations);

        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};