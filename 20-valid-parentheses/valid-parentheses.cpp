#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // If it's a closing bracket, check matching
            if (c == ')') {
                if (st.empty() || st.top() != '(') return false;
                st.pop();
            } else if (c == '}') {
                if (st.empty() || st.top() != '{') return false;
                st.pop();
            } else if (c == ']') {
                if (st.empty() || st.top() != '[') return false;
                st.pop();
            } else {
                // If it's an opening bracket, push to stack
                st.push(c);
            }
        }
        
        // If stack is empty, all brackets matched successfully
        return st.empty();
    }
};