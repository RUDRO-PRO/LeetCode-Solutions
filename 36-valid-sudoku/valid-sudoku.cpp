#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track numbers 1-9 for each row, column, and 3x3 box
        // Index 0 is unused, indices 1-9 correspond to the digits '1' through '9'
        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                int box_index = (i / 3) * 3 + (j / 3);

                // If the number already exists in the current row, col, or box, it's invalid
                if (row[i][num] || col[j][num] || box[box_index][num]) {
                    return false;
                }

                // Mark the number as seen
                row[i][num] = 1;
                col[j][num] = 1;
                box[box_index][num] = 1;
            }
        }

        return true;
    }
};