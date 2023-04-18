#include <iostream>
#include <vector>

using namespace std;

const int N = 100;
vector<vector<int>> board(N, vector<int>(N, 0));
bool visited[N][N] = {false};

bool dfs(int x, int y, int targetX, int targetY) {
    visited[x][y] = true;
    if (x == targetX && y == targetY) {
        return true;
    }
    if (x > 0 && !visited[x-1][y] && board[x-1][y] != 1) {
        if (dfs(x-1, y, targetX, targetY)) {
            return true;
        }
    }
    if (x < N-1 && !visited[x+1][y] && board[x+1][y] != 1) {
        if (dfs(x+1, y, targetX, targetY)) {
            return true;
        }
    }
    if (y > 0 && !visited[x][y-1] && board[x][y-1] != 1) {
        if (dfs(x, y-1, targetX, targetY)) {
            return true;
        }
    }
    if (y < N-1 && !visited[x][y+1] && board[x][y+1] != 1) {
        if (dfs(x, y+1, targetX, targetY)) {
            return true;
        }
    }
    return false;
}

int main() {
    int startX, startY, targetX, targetY;

    // Set the start and target nodes
    startX = 0;
    startY = 0;
    targetX = 5;
    targetY = 5;

    // Set some obstacles in the board
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    if (dfs(startX, startY, targetX, targetY)) {
        cout << "Path found from (" << startX << ", " << startY << ") to (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "No path found from (" << startX << ", " << startY << ") to (" << targetX << ", " << targetY << ")" << endl;
    }

    return 0;
}
