#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to prevent overflow when taking absolute values
        long long dvd = llabs(dividend);
        long long dvs = llabs(divisor);
        long long quotient = 0;

        // Subtract shifted multiples of the divisor from the dividend
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};