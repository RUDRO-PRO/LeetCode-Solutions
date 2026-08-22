#include <string>
#include <iostream>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";
        
        std::string current = "1";
        
        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int length = current.length();
            
            for (int j = 0; j < length; ++j) {
                int count = 1;
                // Count consecutive identical characters
                while (j + 1 < length && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
                // Append count and the character to the next sequence
                next += std::to_string(count) + current[j];
            }
            current = next;
        }
        
        return current;
    }
};