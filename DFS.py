def is_valid(x, y, size, visited):
    return 0 <= x < size and 0 <= y < size and not visited[x][y]

def is_on_boundary(x, y, size):
    return x == 0 or x == size - 1 or y == 0 or y == size - 1

def DFS(x, y, size, visited, steps):
    if is_on_boundary(x, y, size):
        return steps

    min_steps = float('inf')
    visited[x][y] = True

    for i in range(8):
        newX, newY = x + dx[i], y + dy[i]
        if is_valid(newX, newY, size, visited):
            result = DFS(newX, newY, size, visited, steps + 1)
            if result != -1:
                min_steps = min(min_steps, result)

    visited[x][y] = False  # backtrack
    return min_steps if min_steps != float('inf') else -1

dx = [2, 2, -2, -2, 1, 1, -1, -1]
dy = [1, -1, 1, -1, 2, -2, 2, -2]

size = int(input("Enter the size of the chessboard (n x n): "))
startX, startY = map(int, input("Enter the starting position (x y): ").split())
visited = [[False] * size for _ in range(size)]
print(f"Using DFS, the knight can reach the boundary in {DFS(startX, startY, size, visited, 0)} steps.")
