#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.length();
        // prev2 corresponds to dp[i-2], prev1 corresponds to dp[i-1]
        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1]

        for (int i = 2; i <= n; ++i) {
            int current = 0;

            // Check single digit: s[i-1]
            if (s[i - 1] != '0') {
                current += prev1;
            }

            // Check two digits: s[i-2...i-1]
            int two_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two_digit >= 10 && two_digit <= 26) {
                current += prev2;
            }

            // Move forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};