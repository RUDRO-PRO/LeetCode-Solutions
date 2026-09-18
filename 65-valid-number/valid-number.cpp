class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                seenDigit = true;
            } 
            else if (c == '+' || c == '-') {
                // Signs are only valid at the start, or immediately after an exponent
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == 'e' || c == 'E') {
                // Exponents are only valid if we haven't seen one yet AND we have seen a digit
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset because we MUST have digits after the exponent
            } 
            else if (c == '.') {
                // Dots are only valid if we haven't seen a dot yet AND we haven't seen an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else {
                // Any other character (letters other than e/E, symbols) makes it invalid
                return false;
            }
        }
        
        // The string must end with a valid digit (e.g., "1e" is invalid, "1e2" is valid)
        return seenDigit;
    }
};