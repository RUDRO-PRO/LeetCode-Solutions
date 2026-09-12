#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Traverse Right
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = val++;
            }
            top++;
            
            // 2. Traverse Down
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = val++;
            }
            right--;
            
            // 3. Traverse Left
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = val++;
                }
                bottom--;
            }
            
            // 4. Traverse Up
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = val++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};