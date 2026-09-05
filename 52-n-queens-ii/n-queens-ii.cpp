class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // mask with the first n bits set to 1
        int full_mask = (1 << n) - 1;
        
        solve(0, 0, 0, full_mask, count);
        return count;
    }

private:
    void solve(int cols, int diag1, int diag2, int full_mask, int& count) {
        if (cols == full_mask) {
            count++;
            return;
        }

        // Available valid positions in the current row
        int available_positions = full_mask & ~(cols | diag1 | diag2);

        while (available_positions > 0) {
            // Pick the lowest set bit (rightmost valid column)
            int p = available_positions & -available_positions;
            
            // Remove the chosen position
            available_positions -= p;
            
            // Recurse to next row:
            // - cols tracks occupied columns
            // - diag1 shifts left for the next row (top-left to bottom-right)
            // - diag2 shifts right for the next row (top-right to bottom-left)
            solve(cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, full_mask, count);
        }
    }
};