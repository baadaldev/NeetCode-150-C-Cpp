/**
 * LeetCode 36: Valid Sudoku
 * Time Complexity: O(1) - 81 cells
 * Space Complexity: O(1)
 */
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;
            int val = board[r][c] - '1';
            int boxIdx = (r / 3) * 3 + (c / 3);
            int mask = 1 << val;
            if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIdx] & mask)) {
                return false;
            }
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[boxIdx] |= mask;
        }
    }
    return true;
}
