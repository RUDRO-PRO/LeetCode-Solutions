#include <string>
#include <vector>
#include <cstring>

class Solution {
private:
    int memo[30][30];

    bool dp(int i, int j, const std::string& s, const std::string& p) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (j == p.length()) {
            return memo[i][j] = (i == s.length());
        }

        bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
        bool ans = false;

        if (j + 1 < p.length() && p[j + 1] == '*') {
            ans = dp(i, j + 2, s, p) || (first_match && dp(i + 1, j, s, p));
        } else {
            ans = first_match && dp(i + 1, j + 1, s, p);
        }

        return memo[i][j] = ans;
    }

public:
    bool isMatch(std::string s, std::string p) {
        std::memset(memo, -1, sizeof(memo));
        return dp(0, 0, s, p);
    }
};