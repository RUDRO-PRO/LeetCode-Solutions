#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;

        while (sIdx < sLen) {
            // Case 1: Characters match directly, or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Pattern has '*', record star position and assume it matches 0 characters first
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++;
            }
            // Case 3: Mismatch occurs, but we previously encountered a '*' -> backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                sTmpIdx++;
                sIdx = sTmpIdx;
            }
            // Case 4: Mismatch and no '*' to backtrack to
            else {
                return false;
            }
        }

        // Consume any remaining trailing '*' characters in pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};