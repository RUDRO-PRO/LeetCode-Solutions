#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge cases where no zigzag transformation is needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::string result = "";
        result.reserve(s.length()); // Pre-allocate memory to avoid reallocations

        int n = s.length();
        int cycleLen = 2 * numRows - 2; // The period of the zigzag pattern

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < n; j += cycleLen) {
                // Add character from the main vertical column
                result.push_back(s[j + i]);

                // Add character from the diagonal (only for middle rows and valid bounds)
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    result.push_back(s[j + cycleLen - i]);
                }
            }
        }

        return result;
    }
};