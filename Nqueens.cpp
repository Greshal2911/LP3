#include <iostream>
using namespace std;

int board[20][20];
int n;

bool isSafe(int row, int col) {

    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check left diagonal
    for (int i = row - 1, j = col - 1;i >= 0 && j >= 0;i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check right diagonal
    for (int i = row - 1, j = col + 1;i >= 0 && j < n;i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueens(int row) {

    // All queens placed
    if (row == n)
        return true;

    // Try every column
    for (int col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            // Place queen
            board[row][col] = 1;

            // Move to next row
            if (solveNQueens(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    cout << "Enter number of queens: ";
    cin >> n;

    if (solveNQueens(0)) {

        cout << "Solution:" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
    }
    else {
        cout << "No solution exists.";
    }

    return 0;
}