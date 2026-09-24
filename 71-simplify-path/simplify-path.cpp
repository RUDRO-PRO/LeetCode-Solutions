#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;
        
        // Split the path by the '/' delimiter
        while (std::getline(ss, token, '/')) {
            // Ignore empty strings (caused by consecutive slashes) and current directory "."
            if (token == "" || token == ".") {
                continue;
            } 
            // Go up a level by popping the stack if it's not empty
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            // It's a valid directory/file name (including "...")
            else {
                stack.push_back(token);
            }
        }
        
        // Reconstruct the canonical path
        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }
        
        // If the stack is empty, we are at the root
        return result.empty() ? "/" : result;
    }
};