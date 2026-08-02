#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Find min and max strings in a single pass (O(N) time)
        string min_str = strs[0];
        string max_str = strs[0];
        
        for (const string& s : strs) {
            if (s < min_str) min_str = s;
            if (s > max_str) max_str = s;
        }
        
        // The common prefix of the whole array is the common prefix of min and max
        int i = 0;
        while (i < min_str.size() && i < max_str.size() && min_str[i] == max_str[i]) {
            i++;
        }
        
        return min_str.substr(0, i);
    }
};