class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // As discussed, negative numbers are not palindromes.
        // Also, if the last digit of the number is 0, the first digit must also be 0, which only applies to 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed_half = 0;
        while (x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by reversed_half / 10.
        // For example, when x = 12321, at the end of the loop we get x = 12, reversed_half = 123,
        // so we compare x == reversed_half / 10 (12 == 12).
        return x == reversed_half || x == reversed_half / 10;
    }
};