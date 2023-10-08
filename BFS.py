from collections import deque


def is_valid(x, y, size, visited):
    return 0 <= x < size and 0 <= y < size and not visited[x][y]


def is_on_boundary(x, y, size):
    return x == 0 or x == size - 1 or y == 0 or y == size - 1


def BFS(size, start):
    dx = [2, 2, -2, -2, 1, 1, -1, -1]
    dy = [1, -1, 1, -1, 2, -2, 2, -2]

    visited = [[False] * size for _ in range(size)]
    queue = deque([(start[0], start[1], 0)])  # x, y, steps

    while queue:
        x, y, steps = queue.popleft()

        if is_on_boundary(x, y, size):
            return steps

        for i in range(8):
            newX, newY = x + dx[i], y + dy[i]
            if is_valid(newX, newY, size, visited):
                visited[newX][newY] = True
                queue.append((newX, newY, steps + 1))

    return -1  # No path to boundary


size = int(input("Enter the size of the chessboard (n x n): "))
startX, startY = map(int, input("Enter the starting position (x y): ").split())
print(f"Using BFS, the knight can reach the boundary in {BFS(size, (startX, startY))} steps.")

