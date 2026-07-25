#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Returns the length of the palindrome
        };
        
        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindrome (e.g., "aba")
            int len1 = expandAroundCenter(i, i);
            // Even length palindrome (e.g., "abba")
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = std::max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};