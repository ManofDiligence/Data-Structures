#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for(int i = 0; i < row; i++) {
        // Check if the current column is already occupied by a queen
        // or if it is on the same diagonal as another queen.
        if(board[i] == col || abs(board[i] - col) == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<vector<string>>& res, vector<int>& board, int row, int n) {
    // Base case: All rows are filled, so we have found a valid solution.
    if(row == n) {
        vector<string> solution(n, string(n, '.'));
        for(int i = 0; i < n; i++) {
            solution[i][board[i]] = 'Q';
        }
        res.push_back(solution);
        return;
    }

    // Recursive case: Try placing a queen in each column of the current row.
    for(int col = 0; col < n; col++) {
        if(isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(res, board, row + 1, n);
            board[row] = -1;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> board(n, -1);
    solveNQueens(res, board, 0, n);
    return res;
}

int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
