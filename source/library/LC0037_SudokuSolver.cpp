#include <library/LC0037_SudokuSolver.hpp>

bool isValidDigit(const std::vector<std::vector<char>> &board, const int row, const int col) {
    for (int i = 0; i < 9; ++i) {
        if (col != i && board[row][col] == board[row][i])
            return false;
        if (row != i && board[row][col] == board[i][col])
            return false;

        if (const int row2 = (row / 3) * 3 + i / 3, col2 = (col / 3) * 3 + i % 3;
            (row != row2 || col != col2) && board[row2][col2] == board[row][col])
            return false;
    }
    return true;
}

bool recursiveSolution(std::vector<std::vector<char>> &board, const int index) {
    if (index == 81)
        return true;

    const int row = index / 9;
    const int col = index % 9;

    if (board[row][col] != '.')
        return recursiveSolution(board, index + 1);

    for (char ch = '1'; ch <= '9'; ++ch) {
        board[row][col] = ch;
        if (isValidDigit(board, row, col) && recursiveSolution(board, index + 1))
            return true;
    }
    board[row][col] = '.';
    return false;
}

void LC0037::solveSudoku(std::vector<std::vector<char>> &board) {
    recursiveSolution(board, 0);
}