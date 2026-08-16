#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.length() < totalLen) return result;

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Iterate through each possible offset
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + wordLen <= s.length()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    // If a word appears more times than expected, shrink from the left
                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If we matched all words, record the starting index
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if the word is not in words
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};