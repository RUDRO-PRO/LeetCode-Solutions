class Solution {
public:
    int climbStairs(int n) {
        // Base cases for 1 and 2 steps
        if (n <= 2) {
            return n;
        }
        
        int prev2 = 1; // Ways to reach step n-2
        int prev1 = 2; // Ways to reach step n-1
        int current = 0;
        
        // Calculate ways for each step from 3 up to n
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
};