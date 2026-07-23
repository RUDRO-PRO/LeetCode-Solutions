class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_index;
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            if (char_index.find(c) != char_index.end() && char_index[c] >= left) {
                left = char_index[c] + 1;
            }
            char_index[c] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};