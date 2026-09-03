class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n; // Prevent overflow when n = INT_MIN
        
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            exp /= 2;
        }
        
        return result;
    }
};