#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Use a vector of size 128 to store character counts (ASCII)
        vector<int> target_counts(128, 0);
        for (char c : t) {
            target_counts[c]++;
        }

        int left = 0;
        int right = 0;
        int required_chars = t.length();
        int min_len = INT_MAX;
        int min_start = 0;

        while (right < s.length()) {
            // Expand the window by including the character at the right pointer
            char current_char = s[right];
            if (target_counts[current_char] > 0) {
                required_chars--;
            }
            target_counts[current_char]--;
            right++;

            // Shrink the window from the left as long as it contains all required characters
            while (required_chars == 0) {
                // Update the minimum window if the current one is smaller
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }

                // Remove the character at the left pointer from the window
                char left_char = s[left];
                target_counts[left_char]++;
                if (target_counts[left_char] > 0) {
                    required_chars++;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};