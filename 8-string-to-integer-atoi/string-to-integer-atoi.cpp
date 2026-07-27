class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) return 0;
        
        // Step 2: Check sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        // Step 3: Convert digits and check overflow dynamically
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Step 4: Pre-check overflow and underflow bounds (INT_MAX = 2147483647, INT_MIN = -2147483648)
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};