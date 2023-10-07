#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

class Chessboard {
private:
    int n;
    const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

public:
    Chessboard(int size) : n(size) {}

    int bfs_min_steps_to_border(int startX, int startY) {
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::queue<std::tuple<int, int, int>> q; // x, y, steps
        q.push({ startX, startY, 0 });
        visited[startX][startY] = true;

        while (!q.empty()) {
            int x, y, steps;
            std::tie(x, y, steps) = q.front();
            q.pop();

            if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
                return steps;
            }

            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({ newX, newY, steps + 1 });
                }
            }
        }

        return -1;
    }
};

int main() {
    int n, startX, startY;
    std::cout << "请输入棋盘大小 n: ";
    std::cin >> n;
    Chessboard board(n);
    std::cout << "请输入马的初始位置 (x y): ";
    std::cin >> startX >> startY;

    int steps = board.bfs_min_steps_to_border(startX, startY);
    std::cout << "马至少需要 " << steps << " 步到达棋盘边界。" << std::endl;
    return 0;
}
