#include <iostream>
#include <vector>
#include <climits>

class ChessBoard {
private:
    int size;
    std::vector<std::vector<bool>> visited;

public:
    ChessBoard(int n) : size(n), visited(n, std::vector<bool>(n, false)) {}

    bool isValid(int x, int y) {
        return x >= 0 && x < size && y >= 0 && y < size && !visited[x][y];
    }

    bool isOnBoundary(int x, int y) {
        return x == 0 || x == size - 1 || y == 0 || y == size - 1;
    }

    void markVisited(int x, int y) {
        visited[x][y] = true;
    }
};

int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

/这里应用递归实现/
int DFS(ChessBoard& board, int x, int y, int steps) {
    if (board.isOnBoundary(x, y)) {
        return steps;
    }
    board.markVisited(x, y);
    int minSteps = INT_MAX;
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (board.isValid(newX, newY)) {
            int result = DFS(board, newX, newY, steps + 1);
            if (result != -1) {
                minSteps = std::min(minSteps, result);
            }
        }
    }
    return minSteps == INT_MAX ? -1 : minSteps;
}

int main() {
    int n;
    std::cout << "Enter the size of the chessboard (n x n): ";
    std::cin >> n;

    int startX, startY;
    std::cout << "Enter the starting position (x y): ";
    std::cin >> startX >> startY;

    ChessBoard board(n);
    int result = DFS(board, startX, startY, 0);
    if (result != -1) {
        std::cout << "The knight can reach the boundary in " << result << " steps from the given position." << std::endl;
    }
    else {
        std::cout << "The knight cannot reach the boundary from the given position." << std::endl;
    }

    return 0;
}
