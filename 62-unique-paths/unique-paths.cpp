class Solution {
public:
    int uniquePaths(int m, int n) {
        // Choose the smaller step count to minimize iterations
        int N = m + n - 2;
        int r = std::min(m - 1, n - 1);
        
        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result = result * (N - r + i) / i;
        }
        
        return static_cast<int>(result);
    }
};