class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool col0 = false; 

        // Step 1: Use the first row and first column to mark zero elements
        for (int i = 0; i < m; i++) {
            // If any element in the first column is 0, mark col0 to true
            if (matrix[i][0] == 0) col0 = true;
            
            // Mark the rest of the matrix
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Iterate backwards and set zeroes using the marks
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // Finally, process the first column
            if (col0) matrix[i][0] = 0;
        }
    }
};