// NQUEENS

#include <bits/stdc++.h>
using namespace std;

// SAFE CHECK
bool issafe(vector<string> &board, int row, int col, int n) {

    // same row (not actually needed in N-Queens, but included in your logic)
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') return false;
    }

    // same column
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // left upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // right upper diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}


// RECURSION
void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {

    // base case
    if (row == n) {
        ans.push_back(board);
        return;
    }

    // try all columns
    for (int col = 0; col < n; col++) {

        if (issafe(board, row, col, n)) {

            board[row][col] = 'Q';     // place queen
            nqueens(board, row + 1, n, ans);
            board[row][col] = '.';     // backtrack
        }
    }
}


// DRIVER FUNCTION
vector<vector<string>> solveNQueens(int n) {

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nqueens(board, 0, n, ans);
    return ans;
}


// MAIN (for testing)
int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total Solutions = " << solutions.size() << "\n\n";

    for (auto &board : solutions) {
        for (string row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
